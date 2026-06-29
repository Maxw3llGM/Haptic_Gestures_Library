#include "Haptic_Gestures.hpp"


class Wall: public std_haptic_effect{
    private:

    Function_Generator fg;
    double strength;
    double offset=0;
    double range=0.25;

    public:
    Wall(config_struct cf, input_variables * ins);

    double normalized_position(double position, double st_post);
    void map_inputs();
    moteus_commands calculate(double pos, double torque, double velocity);
    void set_strength(double str){strength = str;}
    double get_relative_position(double absolute_position, double delta);
};