#include "Haptic_Gestures.hpp"

class Click : public std_haptic_effect{
  public:
    int clicks;
    double number_of_clicks;
    double max_click_distance;
    double click_strength;
    Click(config_struct cf);

    config_struct get_config();
    void set_config(config_struct cf);

    void set_latched_position(double pos);
    double get_relative_position(double absolute_position, double delta);
    moteus_commands calculate(double pos, double torque, double velocity);
};
