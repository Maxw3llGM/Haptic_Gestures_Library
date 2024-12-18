#include <spring.hpp>

Spring::Spring(config_struct cf):
std_haptic_effect{cf}, ratio{0.0} {
    max_position = config_file.m_d;
    stop_position = config_file.a_z;
}

double Spring::normalized_position(double position, double st_pos){
    return std::clamp(position, -st_pos, st_pos)/st_pos;
}

moteus_commands Spring::calculate(double pos, double torque, double velocity){
    ratio = normalized_position(pos,stop_position);
    m_out.out_position = pos-(max_position*ratio);

    return m_out;
}