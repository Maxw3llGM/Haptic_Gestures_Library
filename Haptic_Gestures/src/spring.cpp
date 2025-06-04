#include <spring.hpp>

Spring::Spring(config_struct cf):
std_haptic_effect{cf}, fg{cf.spring_slope,cf.spring_interpolator,cf.m_d,cf.spring_strength}{ }

double Spring::normalized_position(double position, double st_pos){
    return clip(position, -st_pos, st_pos)/st_pos;
}

// moteus_commands Spring::calculate(double pos, double torque, double velocity){
//     m_out.out_position = torque_Rendering(pos, normalized_position(pos,stop_position));
//     return m_out;
// }
// New Version ( how do )
moteus_commands Spring::calculate(double pos, double torque, double velocity){
    // printf("calculated value: %f \r", fg.calculate(abs(pos))*(std::signbit(pos)? -1: 1));
    m_out.out_position = torque_Rendering(pos, fg.calculate(abs(pos))*(std::signbit(pos)? -1: 1));
    // m_out.out_position = 0.0;
    return m_out;
}