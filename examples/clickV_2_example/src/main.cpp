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
#include <cmath>

static volatile int keepRunning = 1;

moteus_commands m_command;
void intHandler(int dummy){
    keepRunning = 0;
}
ClickV_2 click(true);

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
void print_data(double in_position,double wrapped, double out_position){
    printf("In: %f|Wrapped: %f | Out: %f\n", in_position, wrapped, out_position);
}
int main()
{   
    double in_pos = 1.0;
    double step = 0.01;
    ClickV_2 click(0);
    click.set_max_distance(0.1);
    click.set_active_zone(0.01);
    click.print_consts();
    std::cout << click.max_dist << std::endl;
    for(int i = 0; i < 200; i++){
        const double wrapped_in_pos = std::fmod(in_pos,0.1);

        const moteus_commands result = click.calculate(abs(wrapped_in_pos), 0, 0);
        print_data(in_pos, wrapped_in_pos, result.out_position);
        
        in_pos -= step;
    }
    return 0;
}
