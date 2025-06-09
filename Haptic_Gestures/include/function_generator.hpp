#include <cmath>
#include <algorithm>
#include "clip.hpp"
#include <iostream>
#include <stdlib.h>

class Function_Generator{
    private:
    double beta;
    double alpha;
    double range;
    double x_clipped;
    public:
    Function_Generator();
    Function_Generator(double b, double a, double r);
    double logistic_function(double x);
    double curve_function(double x);
    double calculate(double x);
    void set_beta(double b);
    void set_alpha(double a);
    void set_range(double r);
};
