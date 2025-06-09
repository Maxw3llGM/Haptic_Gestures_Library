#include "Haptic_Gestures_Library.hpp"
#include "Haptic_Gestures.hpp"

Haptic_Gestures_Library::Haptic_Gestures_Library(config_struct conf, int initial_active_effect, bool initial_pressure_control, input_variables * ins): 
click(conf, ins), clickv_2(conf, ins), spin(conf, ins), spring(conf, ins), inertia{conf, ins}, reed_pressure{conf, ins}{
    cf = conf;
    effect_list.push_back(&click);
    // effect_list.push_back(&inertia);
    // effect_list.push_back(&clickv_2);
    // effect_list.push_back(&spin);
    effect_list.push_back(&spring);
    effect_list.push_back(&reed_pressure);
    active_effect_index = initial_active_effect;
    try{
        if(initial_active_effect < 0 || initial_active_effect > effect_list.size()) throw 666;

    active_effects = effect_list[initial_active_effect];
    //Print to consol that a effect was chosen, maybe make that a function.
    }
    catch(...){
        std::cout << "The index must be within the max size of the effect list 2" << std::endl;
    }
}

void Haptic_Gestures_Library::change_effect(int active_effect_index){
    try{
        if(active_effect_index < 0 || active_effect_index > effect_list.size()) throw 666;

        active_effects = effect_list[active_effect_index];
    //Print to consol that a effect was chosen, maybe make that a function.
    }
    catch(...){
        std::cout << "The index must be within the max size of the effect list 2" << std::endl;
    }
}

void Haptic_Gestures_Library::set_active_effect(int step){
    active_effect_index += step;
    if (active_effect_index >= effect_list.size()){
        active_effect_index = 0;
    };
    if (active_effect_index < 0){
        active_effect_index = effect_list.size()-1;
    }

    active_effects = effect_list[active_effect_index];
}

moteus_commands Haptic_Gestures_Library::effect_calculation(double pos, double vel, double tor){
    return active_effects->calculate(pos,vel,tor);
}
void Haptic_Gestures_Library::set_initial_position(double init_position){
    for (int i = 0 ; i < effect_list.size(); i++){
        effect_list[i]->set_initial_position(init_position);
    }

}

void Haptic_Gestures_Library::set_effect_configuration(config_struct configuration){
    active_effects->set_config(configuration);
}
config_struct Haptic_Gestures_Library::get_effect_configuration(){
    return active_effects->get_config();
}

void Haptic_Gestures_Library::print_effect_values(){
    active_effects->print_consts();    
}

Haptic_Gestures_Library::~Haptic_Gestures_Library(){

}