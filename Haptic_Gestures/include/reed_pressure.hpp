#include "Haptic_Gestures.hpp"


class Reed_pressure: public std_haptic_effect{
    private:
    // Stop position is used for normalizing the active range of the turn to 0-1 and no more.
    // Maybe allow for what would be concidered distortion zone past 1 like 1-1.25
    // Max position allows for the scaling of how strong the max strenght of the effect is. 
    double max_position;
    double stop_position;
    double ratio;
    double H,K,A;
    Function_Generator function1;


    public:
    Reed_pressure(config_struct cf);
    void set_H(double new_H) { 
        if(new_H < 2.598){
            std::cout << "Value is too small, Value must be greater or equal to 2.598" << std::endl;
        }else{
            H = new_H; 
            set_K(); 
        }
        
    }
    void set_H() { 
        H = pow(K*4/27, -1/3); 
    }
    void set_K() { 
        K = 27/(pow(H,3) * 4); 
    }
    void set_K(double new_K) {
        if (new_K > 0.3849){
            std::cout << "Value is too big, value must be smaller or equal to 0.3849"<< std::endl;
        }
        else { K = new_K; set_H(); }
    }
    void set_Amplitude(double new_A){ A = new_A; }
    double flow_equation(double pressure);
    moteus_commands calculate(double pos, double torque, double velocity);
};