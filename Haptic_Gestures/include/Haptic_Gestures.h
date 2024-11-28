#ifndef HAPLIB_INCL
#define HAPLIB_INCL

#include <cmath>

struct moteus_commands{
      double out_position;
      double out_torque;
};


class std_haptic_effect {
      //TODO: Set basic boundaries and identifiers that the haptic effects must abid to 
      // (like walls and global variables that are being reused in other effects)
      
      public:
      double initial_position;

      std_haptic_effect();
      std_haptic_effect(double init_pos);
      moteus_commands calculate(double pos, double torque, double velocity);
};

class Click : public std_haptic_effect{
  public:
      double initial_position;
      double max_dist;
      double latched_position;
      double command_torque;
      double command_position;
      double relative_latched_position;
      double relative_position;
      int clicks;
      
      moteus_commands m_out;

      Click(double init_pos);

      void set_initial_position(double pos);
      double get_relative_position(double absolute_position, double delta);
      moteus_commands calculate(double pos, double torque, double velocity);
};
#endif