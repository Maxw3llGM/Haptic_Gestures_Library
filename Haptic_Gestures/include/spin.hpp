#include "Haptic_Gestures.hpp"

class Spin: public std_haptic_effect{
    private:
    double effect_velocity;

    public:
    Spin(config_struct cf);

    config_struct get_config();
    void set_config(config_struct cf);

    void set_velocity(double vel);
    double get_velocity();
    
    moteus_commands calculate(double pos, double torque, double velocity);
};