#include "Haptic_Gestures.hpp"

class ClickV_2 : public std_haptic_effect {
      private:
      double active_zone;
      double zero_point;
      double dead_zone;
      double midpoint;
  public:
      double relative_latched_position;
      int clicks;

      ClickV_2(bool t_m);
      ClickV_2(config_struct cf, bool t_m);

      config_struct get_config();
      void set_config(config_struct config_file);

      void set_max_distance(double m_d);
      double get_active_zone() {return active_zone;};
      void set_midpoint(double value);
      double get_midpoint() {return midpoint;};
      double get_dead_zone() {return dead_zone;};
      double get_max_dist() {return max_distance;};
      void set_latched_position(double pos);
      int set_active_zone(double a_z);
      void print_consts();

      double get_relative_position(double absolute_position, double delta);
      moteus_commands calculate(double pos, double torque, double velocity);

      std::tuple<double,double> get_strength_coef();

};