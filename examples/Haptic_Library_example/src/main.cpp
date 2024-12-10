#include <stdio.h>
#include <atomic>
#include <memory>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <lo/lo.h>
#include <lo/lo_cpp.h>
#include <signal.h>
#include <cmath>
#include <Haptic_Gestures_Library.hpp>

static volatile int keepRunning = 1;

moteus_commands m_command;
void intHandler(int dummy){
    keepRunning = 0;
}
config_struct config_file;

Haptic_Gestures_Library effect_lib(1, 0);

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
    printf("In: %f| Wrapped: %f | Out: %f\n", in_position, wrapped, out_position);
}
void print_data(double in_position, double out_position){
    printf("In: %f | Out: %f\n", in_position, out_position);
}
int main()
{      
    config_struct cf;
    cf.m_d = 0.1;
    cf.a_z = 0.01;
    double in_pos = 0;
    double step = 0.001;
    effect_lib.set_effect_configuration(cf);

    effect_lib.print_effect_values();
    std::cout << "Max Distance: " << effect_lib.get_effect_configuration() << std::endl;
    for(int i = 0; i < 200; i++){
        const double wrapped_in_pos = std::fmod(in_pos,0.1);

        const moteus_commands result = effect_lib.effect_calculation(in_pos, 0, 0);
        // std::cout << "*******************************************" << std::endl;
        print_data(in_pos, effect_lib.get_effects_relative_position(), result.out_position);
        // effect_lib.print_effect_values();
        
        in_pos -= step;
    }
    return 0;
}
