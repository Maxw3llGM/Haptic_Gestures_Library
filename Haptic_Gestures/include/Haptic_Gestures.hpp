#ifndef HAPLIB_INCL
#define HAPLIB_INCL

#include <cmath>
#include <iostream>
#include <stdlib.h>

struct moteus_commands{
      double out_position;
      double out_torque;
};

template<typename T> T clip(const T& n, const T& lower, const T& upper){
      return std::max(lower, std::min(n,upper));
}

struct config_struct{
      public:
      double m_d;
      double a_z;
      double m_kp;
      double m_kd;

      config_struct(){
            m_d = 1.0;
            a_z = 0.5;
            m_kp = 1.0;
            m_kd = 1.0;
      }
      config_struct(double max_dist, double active_zone, double position_coefficient, double velocity_coefficient){
            m_d = max_dist;
            a_z = active_zone;
            m_kp = position_coefficient;
            m_kd = velocity_coefficient;
      }
      friend std::ostream& operator <<(std::ostream& os, config_struct const& x){
            return os << x.m_d << '\n' << x.a_z << '\n' << x.m_kp << '\n' << x.m_kd << '\n';
      }
};

class std_haptic_effect {
      //TODO: Set basic boundaries and identifiers that the haptic effects must abid to 
      // (like walls and global variables that are being reused in other effects)
      
      public:
      bool torque_Mode;
      double m_kp, m_kd;
      double command_torque;
      double command_position;
      double command_velocity;
      double relative_position;
      double latched_position;
      double max_distance;
      config_struct config_file;
      moteus_commands m_out;

      std_haptic_effect();
      std_haptic_effect(bool t_m);
      std_haptic_effect(config_struct cf);
      std_haptic_effect(config_struct cf, bool t_m);
      virtual moteus_commands calculate(double pos, double torque, double velocity) = 0;

      virtual config_struct get_config();
      virtual void set_config(config_struct cf);

      virtual void print_consts();
};
#endif