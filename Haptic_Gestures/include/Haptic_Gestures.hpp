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

      std_haptic_effect() : 
            initial_position{0}, torque_Mode{false} { }
      std_haptic_effect(double init_pos, bool t_m): 
            initial_position{init_pos}, torque_Mode{t_m} { }
      moteus_commands calculate(double pos, double torque, double velocity);
};
#endif