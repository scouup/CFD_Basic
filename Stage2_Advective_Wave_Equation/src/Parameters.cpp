#include "Parameters.h"

const double x_min = 0.0;
const double x_max = 1.0;
const int Nx = 500;

const double a = 0.05;       // Convective velocity
const double CFL = 0.8;     
const double t_end = 10;   

double dx = (x_max - x_min)/(Nx - 1);
double dt = CFL * dx / a;
