#include "Haptic_Gestures.hpp"

std_haptic_effect::std_haptic_effect()
: m_kp{1.0}, m_kd{1.0}, torque_Mode{false},m_out{0.0,0.0}, max_distance{1.0}, latched_position{0.0}, relative_position{0.0},dt{0.1},max_torque{0.5} {
}
std_haptic_effect::std_haptic_effect(config_struct cf): 
config_file{cf}, torque_Mode{0}, m_out{0.0,0.0}, max_distance{0.1}, latched_position{0.0}, relative_position{0.0}, dt{0.1}, max_torque{0.5}{}

moteus_commands std_haptic_effect::calculate(double pos, double torque, double velocity){
    return (moteus_commands){0.0, 0.0};
}

config_struct std_haptic_effect::get_config(){
    return config_file;
}
void std_haptic_effect::set_config(config_struct cf){
    config_file = cf;
}
void std_haptic_effect::print_consts(){
    std::cout << config_file;
}
void std_haptic_effect::set_initial_position(int init_pos){
    init_pos = init_pos;
}

void std_haptic_effect::set_Max_Torque(double new_value){
    config_file.m_d = new_value;
}
double std_haptic_effect::torque_Rendering(double position,double functions_output){
    return position-functions_output;
}