#ifndef HAPLIB_INCL
#define HAPLIB_INCL

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <clip.hpp>
#include <function_generator.hpp>

struct moteus_commands{
      double out_position;
      double out_velocity;
      double out_torque;
};

struct config_struct{
      public:
      double m_d; //max distance
      double a_z; //active zone
      double m_kp; //postitional constant
      double m_kd; //differential constant
      double vel; //velocity

      config_struct(){
            m_d = 1.0;
            a_z = 0.5;
            m_kp = 1.0;
            m_kd = 1.0;
            vel = 0;
      }
      config_struct(double max_dist, double active_zone, double position_coefficient, double velocity_coefficient, double velocity){
            m_d = max_dist;
            a_z = active_zone;
            m_kp = position_coefficient;
            m_kd = velocity_coefficient;
            vel = velocity;
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
      double dt;
      double init_pos;
      double max_torque;
      config_struct config_file;
      moteus_commands m_out;
      Function_Generator fg;
      std_haptic_effect();
      std_haptic_effect(bool t_m);
      std_haptic_effect(config_struct cf);
      std_haptic_effect(config_struct cf, bool t_m);
      virtual moteus_commands calculate(double pos, double torque, double velocity) = 0;
      void set_initial_position(int init_pos);
      config_struct get_config();
      void set_config(config_struct cf);
      double torque_Rendering(double position, double functions_output);
      void set_Max_Torque(double new_value);

      virtual void print_consts();
};
#endif