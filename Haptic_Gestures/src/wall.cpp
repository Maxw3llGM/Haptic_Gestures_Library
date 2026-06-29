#include <cmath>
#include <wall.hpp>

Wall::Wall(config_struct cf, input_variables * ins):
std_haptic_effect{cf, ins}, strength{cf.wall_strength}, fg{cf.spring_slope,cf.spring_interpolator,cf.m_d}{
  // offset = cf.wall_offset;
  // range = cf.wall_m_d;
 }

double Wall::normalized_position(double position, double st_pos){
    return clip(position, -st_pos, st_pos)/st_pos;
}
void Wall::map_inputs(){
    printf("%3.3f, %3.3f, %3.3f, %3.3f\r", ins.In_1,ins.In_2,ins.In_3,ins.In_4);
}
double Wall::get_relative_position(double absolute_position, double delta){
  return absolute_position-delta;
}
moteus_commands Wall::calculate(double pos, double torque, double velocity){
    // printf("calculated value: %f | %f \r",pos, torque_Rendering(pos, -fg.calculate(pos)));
    
    if(abs(pos) > (offset+range)){
      relative_position = get_relative_position(abs(pos), (offset+range));
      m_out.out_cv1 = -strength*fg.calculate(relative_position);
      m_out.out_position = torque_Rendering(pos, ((std::signbit(pos))? -1.0 : 1.0)*m_out.out_cv1);
      // printf("%f, %f, %f, %f\r", pos,offset+range,m_out.out_cv1,m_out.out_position);
    }
    else m_out.out_position = pos;
    return m_out;
}