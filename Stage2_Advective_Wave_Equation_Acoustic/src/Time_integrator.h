#ifndef TIME_INTEGRATOR_H
#define TIME_INTEGRATOR_H

#include <vector>
#include <functional>
using namespace std;

void time_integrate(
    const vector<double>& psi0,
    int Nt,
    vector<double>& psi_final,
    function<void(const vector<double>&, int)> write_callback = nullptr
);

#endif
