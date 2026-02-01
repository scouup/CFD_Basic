#ifndef SPACE_SCHEMES_H
#define SPACE_SCHEMES_H

#include <vector>
#include "Parameters.h"
using namespace std;

using SpatialFunc = vector<double>(*)(const vector<double>&);

// Upwind
vector<double> upwind_space(const vector<double>& u);

// Downwind
vector<double> downwind_space(const vector<double>& u);

// Central
vector<double> central_space(const vector<double>& u);

#endif