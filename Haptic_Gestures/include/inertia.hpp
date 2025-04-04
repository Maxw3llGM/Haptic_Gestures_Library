#include "Haptic_Gestures.hpp"

class Inertia: public std_haptic_effect{
    private:
    double effect_velocity;
    double prev_pos = 0.0;
    double prev_vel = 0.0;

    public:
    Inertia(config_struct cf);

    double get_velocity();
    
    moteus_commands calculate(double pos, double torque, double velocity);
};