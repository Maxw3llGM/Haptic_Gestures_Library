#include "inertia.hpp"

Inertia::Inertia(config_struct cf):
    std_haptic_effect{cf}, prev_pos{init_pos}
{}

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