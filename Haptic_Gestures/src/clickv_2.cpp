#include "clickv_2.hpp"

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
    else latched_position = midpoint+active_zone;

    }
  else latched_position = pos;

  m_out.out_position = latched_position;

  return m_out;

}


