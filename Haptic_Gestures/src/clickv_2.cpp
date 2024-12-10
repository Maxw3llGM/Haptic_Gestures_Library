#include "clickv_2.hpp"

ClickV_2::ClickV_2(bool t_m):
            std_haptic_effect{},
            dead_zone{0.0},
            clicks{0}  
            {
              set_config(config_file);
              midpoint = max_distance/2.0;
              active_zone = midpoint - dead_zone;
              relative_position = -midpoint;
            }
ClickV_2::ClickV_2(config_struct cf, bool t_m):
            std_haptic_effect{cf},
            active_zone{0.025},
            clicks{0}  
            {
              set_config(config_file);
              midpoint = max_distance/2.0;
              dead_zone = midpoint - active_zone;
              relative_position = -midpoint;
            }

void ClickV_2::set_latched_position(double pos){
  latched_position = pos;
}

void ClickV_2::set_max_distance(double m_d) {
  max_distance = m_d;
  midpoint = max_distance/2.0;
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
void ClickV_2::set_midpoint(double value){
  midpoint += value;
  // active_zone = abs(midpoint)-dead_zone + value;
}

void ClickV_2::print_consts(){
  std::cout <<"Active Zone:" << active_zone << " | Dead Zone: " << dead_zone << " | Midpoint " << midpoint << " | Max Distance " << max_distance << std::endl;
}

double ClickV_2::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;
}

std::tuple<double,double> ClickV_2::get_strength_coef() {return {m_kp, m_kd};}



moteus_commands ClickV_2::calculate(double pos, double torque, double velocity){
  //TODO:begin by making it symetrical, will add asymetry traits when I achieve symmetry with all effects.

  // Adjusting the zero point (being the midpoint)
  if (relative_position < -(config_file.m_d/2)){
    set_midpoint(-max_distance); //assuming symmetry (must adjust for asymetrical shapes in the future)
  }
  if (relative_position > +(config_file.m_d/2)){
    set_midpoint(max_distance);
  }

  // now we get the new relative_position based on a adjusted midpoint.
  relative_position = get_relative_position(pos, midpoint);
  /*
  This set's the latching boundaries to be around the midpoint. If this were to be asymmetrical,
  then each active zone would have it's own boarder active_zone_a, and active_zone_b
  */ 
  if (relative_position > -active_zone && relative_position < active_zone){
    if(relative_position >= 0.0){latched_position = midpoint+active_zone;}
    else latched_position = midpoint-active_zone;
  }
  else latched_position = pos;

  m_out.out_position = latched_position;

  return m_out;

}

config_struct ClickV_2::get_config(){
  return config_file;
}

void ClickV_2::set_config(config_struct cf){
  config_file = cf;
  
  set_max_distance(cf.m_d);
  set_active_zone(cf.a_z);

  if (cf.m_kd!= m_kd) m_kd = cf.m_kd;
  if (cf.m_kd!= m_kd) m_kd = cf.m_kp;

  std::cout<< "Modified the values" <<std::endl;
}

