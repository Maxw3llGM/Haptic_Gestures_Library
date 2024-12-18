#include "click.hpp"



Click::Click(config_struct cf, bool t_m): 
            std_haptic_effect(cf, t_m),
            clicks{0}  
            {
              set_config(cf);
            }

void Click::set_latched_position(double pos) {
  latched_position = pos;
}

double Click::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;

}

moteus_commands Click::calculate(double pos, double torque, double velocity){

  // Torque Calculation
  if(1) command_torque = clip<double>(pos, -1.0, 1.0);
  else command_torque = 0;
  m_out.out_torque = command_torque;
  
  // Position Calculation
  // This sets the current position to be the target position the motor is to be at, creating a click effect.
  relative_position = get_relative_position(pos, latched_position);
  if(std::abs(relative_position) < max_distance) m_out.out_position = latched_position;
  else {
    latched_position = pos;
    // TODO: Have the Click effect be a separate effect that is derived from the click effect???
    // clicks = clicks+1*(std::signbit(relative_latched_position)? -1: 1);
  }


  return m_out;
}

config_struct Click::get_config(){
  return config_file;
}

void Click::set_config(config_struct cf){
  config_file = cf;
  max_distance = config_file.m_d;
  std::cout<< "Modified the values" <<std::endl;
}
