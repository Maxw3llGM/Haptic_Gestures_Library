#include "Haptic_Gestures.hpp"


class Spring: public std_haptic_effect{
    private:
    // Stop position is used for normalizing the active range of the turn to 0-1 and no more.
    // Maybe allow for what would be concidered distortion zone past 1 like 1-1.25
    // Max position allows for the scaling of how strong the max strenght of the effect is. 

    Function_Generator fg;
    double strength;

    public:
    Spring(config_struct cf, input_variables * ins);

    double normalized_position(double position, double st_post);
    void map_inputs();
    moteus_commands calculate(double pos, double torque, double velocity);
    void set_strength(double str){strength = str;}
};