#include "Haptic_Gestures.hpp"

class Spin: public std_haptic_effect{
    private:
    double effect_velocity;

    public:
    Spin(config_struct cf, input_variables * ins);

    void set_velocity(double vel);
    double get_velocity();
    void map_inputs();
    moteus_commands calculate(double pos, double torque, double velocity);
};