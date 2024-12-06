#include <stdio.h>
#include <atomic>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <lo/lo.h>
#include <lo/lo_cpp.h>
#include <signal.h>
#include <Haptic_Gestures.h>

static volatile int keepRunning = 1;

moteus_commands m_command;
void intHandler(int dummy){
    keepRunning = 0;
}
Click click(0,true);
    
std::atomic<double> effect_data{0.0};
    
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

    printf("path: <%s>\n", path);
    for (i = 0; i < argc; i++) {
        printf("arg %d '%c' ", i, types[i]);
        lo_arg_pp((lo_type)types[i], argv[i]);
        printf("\n");
    }

    printf("\n");
    fflush(stdout);

    return 1;
}

int main()
{
    //Catches when the user presses CTL-C and ends the loops properly.
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
            FD_ZERO(&rfds);
            FD_SET(lo_fd, &rfds);
            retval = select(lo_fd + 1, &rfds, NULL, NULL, 0); 
           if (retval == -1) {

                printf("select() error\n");
                exit(1);

            } else if (retval > 0) {

                if (FD_ISSET(lo_fd, &rfds)) {

                    lo_server_recv_noblock(s, 0);
                    m_command = click.calculate(effect_data.load(),0.0,0.0);
                    lo_send(t, "/eq_out", "f", m_command.out_position);
                }
            }
        } while (keepRunning);

    }
    return 0;
}
