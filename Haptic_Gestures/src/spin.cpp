#include "spin.hpp"

Spin::Spin(config_struct cf):
    std_haptic_effect{cf}
{
    effect_velocity = cf.vel;
}

config_struct Spin::get_config(){
    return config_file;
}

void Spin::set_config(config_struct cf){
    config_file = cf;
    effect_velocity = config_file.vel;
}

void Spin::set_velocity(double vel){
    effect_velocity = vel;
    config_file.vel = vel;
}
moteus_commands Spin::calculate(double pos, double torque, double velocity){
    m_out.out_velocity = effect_velocity;
    m_out.out_position = pos;
    m_out.out_torque = 0;
    
    return m_out;
}

//TODO: Fixed the moteus_commands struct 
//(aka how m_out works. Does it get generated at the creation of the effect?)
//or should it be instanced when the effect is made.
// how does error handly occure when a value does not get changed after one cycle and the effect begins to spin out.

//TODO: Create std_Haptic_Effect standard functions. Like set and get config files.
// Like that each effect just needs to pull from the config file and not have any local variables.

