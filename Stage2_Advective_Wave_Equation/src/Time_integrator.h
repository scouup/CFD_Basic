#ifndef TIME_INTEGRATOR_H
#define TIME_INTEGRATOR_H

#include <vector>
#include "Space_Scheme.h"
using namespace std;

vector<double> time_integrate(vector<double> u0, SpatialFunc space_scheme, int Nt);

#endif
