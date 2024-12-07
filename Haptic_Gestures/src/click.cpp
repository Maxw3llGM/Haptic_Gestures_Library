#include "Haptic_Gestures.h"

std_haptic_effect::std_haptic_effect() : 
                                    initial_position{0}, torque_Mode{false} { }
std_haptic_effect::std_haptic_effect(double init_pos, bool t_m): 
                                    initial_position{init_pos}, torque_Mode{t_m} { }

Click::Click(double init_pos, bool t_m): 
            std_haptic_effect(init_pos, t_m),
            latched_position{init_pos}, 
            max_dist{0.05}, 
            m_out{0.0,0.0}, 
            clicks{0}  
            { }

void Click::set_initial_position(double pos){
  initial_position = pos;
  latched_position = pos;
}
double Click::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;
}
moteus_commands Click::calculate(double pos, double torque, double velocity){
  relative_position = initial_position-pos;

  // Torque Calculation
  if(torque_Mode) command_torque = relative_position;
  else command_torque = 0;
  m_out.out_torque = command_torque;
  
  // Position Calculation
  // This sets the current position to be the target position the motor is to be at, creating a click effect.
  relative_latched_position = get_relative_position(pos, latched_position);
  if(std::abs(relative_latched_position) < max_dist) m_out.out_position = latched_position;
  else {
    latched_position = pos;
    // TODO: Have the Click effect be a separate effect that is derived from the click effect???
    clicks = clicks+1*(std::signbit(relative_latched_position)? -1: 1);
  }
  return m_out;
}

ClickV_2::ClickV_2(bool t_m):
            latched_position{0.0}, 
            dead_zone{0.0},
            max_dist{0.05}, 
            m_out{0.0,0.0}, 
            clicks{0}  
            {
              midpoint = max_dist/2.0;
              active_zone = midpoint - dead_zone;
            }

void ClickV_2::set_latched_position(double pos){
  latched_position = pos;
}
void ClickV_2::set_max_distance(double m_d) {
  max_dist = m_d;
  midpoint = max_dist/2.0;
  active_zone = midpoint-dead_zone;
  }
int ClickV_2::set_active_zone(double a_z){
  if(active_zone > midpoint){
    return -1;
  }
  else{
    active_zone = a_z;
    dead_zone = midpoint-active_zone;
  }
  return 0;
  
}
void ClickV_2::print_consts(){
  std::cout <<"Active Zone:" << active_zone << " | Dead Zone: " << dead_zone << " | Midpoint " << midpoint << " | Max Distance " << max_dist << std::endl;
}
double ClickV_2::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;
}

std::tuple<double,double> ClickV_2::get_strength_coef() {return {m_kp, m_kd};}

moteus_commands ClickV_2::calculate(double pos, double torque, double velocity){
  if (pos <= midpoint+active_zone && pos >= midpoint-active_zone) {

    if(pos <= midpoint) latched_position = midpoint-active_zone;
    if(pos > midpoint) latched_position = midpoint+active_zone;

    }
  else latched_position = pos;

  m_out.out_position = latched_position;

  return m_out;


  // if (relative_position >= dead_zone && relative_position <= (dead_zone + active_zone)){

  //   // Setting anchor points
  //   if(relative_position <= midpoint)latched_position = dead_zone;
  //   else latched_position = dead_zone + active_zone;

  //   //Setting different haptic salience values.
  //   if(relative_position <= midpoint+s2 && relative_position >= midpoint-s2) {m_kd = 1; m_kp = 1;}
  //   else {m_kd = 0.5; m_kp = 0.5;}
  // }else latched_position = relative_position;

  // m_out.out_position = latched_position + initial_position;
  // 
  // return m_out;
}


