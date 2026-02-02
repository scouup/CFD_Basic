#include "Parameters.h"

const double x_min = -1.0;
const double x_max = 1.0;
const int Nx = 1000;

const double c0 = 0.02;
const double U = 0.001;
const double CFL = 0.8;     
const double t_end = 20;   

double dx = (x_max - x_min)/(Nx - 1);
double dt = CFL * dx / (c0+U);

const int output_interval = 1;    
const std::string output_dir = "output/Instant";