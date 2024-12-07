#ifndef HAPLIB_INCL
#define HAPLIB_INCL

#include <cmath>
#include <tuple>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct moteus_commands{
      double out_position;
      double out_torque;
};


class std_haptic_effect {
      //TODO: Set basic boundaries and identifiers that the haptic effects must abid to 
      // (like walls and global variables that are being reused in other effects)
      
      public:
      bool torque_Mode;
      double command_torque;
      double command_position;
      double command_velocity;
      double initial_position;
      double initial_velocity;
      double initial_torque;

      std_haptic_effect();
      std_haptic_effect(double init_pos, bool t_m);
      moteus_commands calculate(double pos, double torque, double velocity);
};

class Click : public std_haptic_effect{
      
  public:
      double max_dist;
      double latched_position;
      double relative_latched_position;
      double relative_position;
      int clicks;
      
      moteus_commands m_out;

      Click(double init_pos, bool t_m);

      void set_initial_position(double pos);
      double get_relative_position(double absolute_position, double delta);
      moteus_commands calculate(double pos, double torque, double velocity);
};

class ClickV_2{
      private:
      double m_kp;
      double m_kd;
      double s2;
      double zero_point;
      double dead_zone;
      double active_zone;
      double midpoint;
      double click_slope;
      double approach_slope;
      double latched_position;
      double max_dist;
  public:
      
      
      double relative_latched_position;
      double relative_position;
      int clicks;
      
      moteus_commands m_out;

      ClickV_2(bool t_m);
      void set_max_distance(double m_d);
      double get_active_zone() {return active_zone;};
      double get_midpoint() {return midpoint;};
      double get_dead_zone() {return dead_zone;};
      double get_max_dist() {return max_dist;};
      void set_latched_position(double pos);
      int set_active_zone(double a_z);
      void print_consts();
      double get_relative_position(double absolute_position, double delta);
      moteus_commands calculate(double pos, double torque, double velocity);
      std::tuple<double,double> get_strength_coef();
};
#endif