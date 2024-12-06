/**
 * Copyright 2019 Bradley J. Snyder <snyder.bradleyj@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <atomic>
#include <memory>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "pid.h"
#include <lo/lo.h>
#include <lo/lo_cpp.h>
#include <stdio.h>
#include <signal.h>
#include <Haptic_Gestures.h>


static volatile int keepRunning = 1;
moteus_commands m_command;
Click click(0,true);
void intHandler(int dummy){
    keepRunning = 0;
}
std::atomic<double> effect_data{0.0};
double inc = 0.0;
double val = 0.0;

void error(int num, const char *msg, const char *path)
{
    printf("liblo server error %d in path %s: %s\n", num, path, msg);
}

/* catch any incoming messages and display them. returning 1 means that the
 * message has not been fully handled and the server should try other methods */
int user_input_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, lo_message data, void *user_data)
{
    int i;

    effect_data.store(argv[0]->f);

    // printf("path: <%s>\n", path);
    // for (i = 0; i < argc; i++) {
    //     printf("arg %d '%c' ", i, types[i]);
    //     lo_arg_pp((lo_type)types[i], argv[i]);
    //     printf("\n");
    // }

    // printf("\n");
    // fflush(stdout);

    return 1;
}

int main() {

    PID pid = PID(0.01, 10, -10, 0.0001, 0.00001, 0.00005);

    signal(SIGINT, intHandler);
    int lo_fd;
    fd_set rfds;
    int retval;

    /* start a new server on port 9001 */
    lo_server s = lo_server_new("9001", error);
    lo_address t = lo_address_new(NULL, "9000");

    /* add method that will match any path and args */
    lo_server_add_method(s, "/user_input", "f", user_input_handler, NULL);


    /* get the file descriptor of the server socket, if supported */
    lo_fd = lo_server_get_socket_fd(s);

    if (lo_fd > 0) {

        /* select() on lo_server fd is supported, so we'll use select()
         * to watch both stdin and the lo_server fd. */
        do {
            lo_server_recv_noblock(s, 0);
            m_command = click.calculate(effect_data.load(),0.0,0.0);
            
            inc = pid.calculate(effect_data.load(), val);
            val += inc;
            // printf("inc: %f, val: %f\n", inc, val); 
            lo_send(t, "/eq_out", "f", m_command.out_position);
            lo_send(t, "/PID/val_out", "f", val);
            lo_send(t, "/PID/inc_out", "f", inc);
        } while (keepRunning);

    }
    return 0;
}