#include "Haptic_Gestures.hpp"
#include "click.hpp"
#include "clickv_2.hpp"
#include <vector>

class Haptic_Gestures_Library{
    private:
        Click click;
        ClickV_2 clickv_2;
        std::vector< std_haptic_effect * > effect_list;
        std_haptic_effect * active_effects;
        int list_size;
        int active_effect_index;
        config_struct cf;
    public:
        Haptic_Gestures_Library(config_struct conf, int initial_active_effect, bool initial_pressure_control);
        ~Haptic_Gestures_Library();

        void change_effect(int active_effect_index);
        moteus_commands effect_calculation(double pos, double vel, double tor);

        void set_effect_configuration(config_struct configuration);

        config_struct get_effect_configuration();
        void print_effect_values();
        double get_effects_relative_position(){
            return active_effects->relative_position;
        }
        void set_active_effect(int index);

    
};