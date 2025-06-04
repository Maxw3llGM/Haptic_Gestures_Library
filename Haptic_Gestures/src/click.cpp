#include "click.hpp"



Click::Click(config_struct cf): 
            std_haptic_effect(cf),
            clicks{0}  
            {
              set_config(cf);
              number_of_clicks = cf.click_number_of_clicks;
              max_click_distance = config_file.click_m_d/number_of_clicks;
              click_strength = config_file.click_strength;
            }

void Click::set_latched_position(double pos) {
  latched_position = pos;
}

double Click::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;

}

moteus_commands Click::calculate(double pos, double torque, double velocity){

  // Torque Calculation
  if(0) command_torque = clip<double>(pos, -.1, .1);
  else command_torque = 0;
  m_out.out_torque = command_torque;
  

  // Position Calculation
  // This sets the current position to be the target position the motor is to be at, creating a click effect.
  relative_position = get_relative_position(pos, latched_position);
  double normalized_position = round((relative_position/max_click_distance)*1000.0)/1000.0;
  // std::cout << latched_position-((relative_position/max_click_distance)*0.05) << std::endl;
  if(std::abs(relative_position) < max_click_distance) {
    m_out.out_position = latched_position - normalized_position*click_strength;
    m_out.out_cv1 = normalized_position;
    }
  else {
    latched_position = pos;
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
