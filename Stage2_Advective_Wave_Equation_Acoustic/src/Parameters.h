#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>
extern const double x_min;
extern const double x_max;
extern const int Nx;

extern const double c0; 
extern const double U;       
extern const double CFL;     
extern const double t_end;   

extern double dx;           
extern double dt;            

extern const int output_interval;         
extern const std::string output_dir;     
#endif
