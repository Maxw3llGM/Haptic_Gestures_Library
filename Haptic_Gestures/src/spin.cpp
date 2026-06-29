#include "spin.hpp"
#include "Haptic_Gestures.hpp"

Spin::Spin(config_struct cf, input_variables * ins):
    std_haptic_effect{cf, ins}
{
    set_config(cf);
    effect_velocity = cf.spin_vel;
    // printf("%f",cf.spin_vel);
}

void Spin::set_velocity(double vel){
    config_file.vel = vel;
}
void Spin::map_inputs(){
    printf("%3.3f, %3.3f, %3.3f, %3.3f\r", ins.In_1,ins.In_2,ins.In_3,ins.In_4);
}
moteus_commands Spin::calculate(double pos, double torque, double velocity){
    auto vel_val = effect_velocity;

    m_out.out_position = m_out.out_position = torque_Rendering(pos, vel_val);
    // printf("%f, %f, %f \r",vel_val,pos, m_out.out_position);
    
    return m_out;
}

