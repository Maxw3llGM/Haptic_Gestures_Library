#include "function_generator.hpp"


Function_Generator::Function_Generator(): beta{2.0}, alpha{1.0}, range{1.0}, strength{1.0}{
    printf("Initializing Functions Generator's Values \n%f, %f, %f, %f \n", beta, alpha, range, strength);
}

Function_Generator::Function_Generator(double b, double a, double r, double str){
    set_beta(b);
    set_alpha(a);
    set_range(r);
    set_strength(str);
    printf("Initializing Functions Generator's Values \n%f, %f, %f, %f \n", beta, alpha, range, strength);

}

void Function_Generator::set_beta(double b){
    beta = clip(b, 0.2, 10.0);
}

void Function_Generator::set_alpha(double a){
    alpha = clip(a,0.0, 1.0);
}

void Function_Generator::set_range(double r){
    range = clip(r,0.0, 1.0);
}

void Function_Generator::set_strength(double str){
    strength = clip(str, 0.0, 1.0);
}

double Function_Generator::logistic_function(double x){
    return strength / ( 1.0 + pow( x / ( range - x ), - beta ) );
}

double Function_Generator::curve_function(double x){
    return pow(x, beta);
}

double Function_Generator::calculate(double x){
    x_clipped = clip(x, 0.00, range);
    // printf("%f ,%f ,%f ,%f \r",x_clipped,range,strength,logistic_function( x_clipped ));
    return alpha * logistic_function( x_clipped ) + ( 1.0 - alpha ) * curve_function(x_clipped);
}
