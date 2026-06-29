#include "inertia.hpp"
#include "Haptic_Gestures.hpp"

Inertia::Inertia(config_struct cf, input_variables * ins):
    std_haptic_effect{cf, ins}, prev_pos{init_pos}
{}
void Inertia::map_inputs(){
    printf("%3.3f, %3.3f, %3.3f, %3.3f\r", ins.In_1,ins.In_2,ins.In_3,ins.In_4);
}
moteus_commands Inertia::calculate(double pos, double torque, double velocity){
    // const double vel = static_cast<float>(round(velocity * 10.)) / 10.;
    // m_out.out_torque = 
    // m_out.out_velocity = NAN;
    const double dp = prev_pos-pos;
    m_out.out_position = pos - dp;
    std::cout << dp << std::endl;
    prev_pos = pos;
    return m_out;
}