#include "reed_pressure.hpp"

Reed_pressure::Reed_pressure(config_struct cf){
    config_file = cf;
    H = sqrt(27.0)/2.0;
    set_K();
    A = 0.01;
}
double Reed_pressure::flow_equation(double pressure)  {return A * (H * pow( abs( pressure ), 0.5 ) - pow( abs( pressure ), 1.5 )/K);}
moteus_commands Reed_pressure::calculate(double pos, double torque, double velocity){
    m_out.out_position = torque_Rendering(pos, flow_equation(clip(pos,-max_position,max_position)));
    // printf("%f5,%f5,%f5 \r",pos,flow_equation(pos),torque_Rendering(pos, flow_equation(pos)));

    return m_out;
}