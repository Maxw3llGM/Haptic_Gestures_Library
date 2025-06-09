#include <spring.hpp>

Spring::Spring(config_struct cf, input_variables * ins):
std_haptic_effect{cf, ins}, strength{cf.spring_strength}, fg{cf.spring_slope,cf.spring_interpolator,cf.m_d}{ }

double Spring::normalized_position(double position, double st_pos){
    return clip(position, -st_pos, st_pos)/st_pos;
}
void Spring::map_inputs(){
    printf("%3.3f, %3.3f, %3.3f, %3.3f\r", ins.In_1,ins.In_2,ins.In_3,ins.In_4);
}
moteus_commands Spring::calculate(double pos, double torque, double velocity){
    // printf("calculated value: %f | %f \r",pos, torque_Rendering(pos, -fg.calculate(pos)));
    m_out.out_cv1 = -strength*fg.calculate(pos);
    m_out.out_position = torque_Rendering(pos, m_out.out_cv1);
    return m_out;
}