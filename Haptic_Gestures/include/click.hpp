#include "Haptic_Gestures.hpp"

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