#include "Haptic_Gestures.h"

std_haptic_effect::std_haptic_effect() : initial_position{0} { }
std_haptic_effect::std_haptic_effect(double init_pos) : initial_position{init_pos} { }

Click::Click(double init_pos):
          initial_position{init_pos},
          latched_position{0}, 
          max_dist{0.05}, 
          m_out{0.0,0.0}, 
          clicks{0}  
          { }

void Click::set_initial_position(double pos){
  initial_position = pos;
  latched_position = pos;
}
double Click::get_relative_position(double absolute_position, double delta){
  return (absolute_position-delta);
}
moteus_commands Click::calculate(double pos, double torque, double velocity){
  relative_position = initial_position-pos;

  // Torque Calculation
  command_torque = relative_position;
  m_out.out_torque = command_torque;
  
  // Position Calculation
  // This sets the current position to be the target position the motor is to be at, creating a click effect.
  relative_latched_position = get_relative_position(pos, latched_position);
  if(abs(relative_latched_position) < max_dist) m_out.out_position = latched_position;
  else {
    latched_position = pos;
    // TODO: Have the Click effect be a separate effect that is derived from the click effect???
    clicks = clicks+1*(std::signbit(relative_latched_position)? -1: 1);
  }
  return m_out;
}