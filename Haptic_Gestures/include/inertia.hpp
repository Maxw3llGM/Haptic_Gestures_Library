#include "Haptic_Gestures.hpp"

class Inertia: public std_haptic_effect{
    private:
    double effect_velocity;
    double prev_pos = 0.0;
    double prev_vel = 0.0;

    public:
    Inertia(config_struct cf, input_variables * ins);

    double get_velocity();
    void map_inputs();
    moteus_commands calculate(double pos, double torque, double velocity);
};