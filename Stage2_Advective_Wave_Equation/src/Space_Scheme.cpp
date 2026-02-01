#include "Space_Scheme.h"

//Upwind
vector<double> upwind_space(const vector<double>& u) {
    vector<double> u_new = u;
    for(int i=1; i<Nx; ++i)
        u_new[i] = u[i] - CFL*(u[i]-u[i-1]);
    return u_new;
}

//Downwind
vector<double> downwind_space(const vector<double>& u) {
    vector<double> u_new = u;
    for(int i=1; i<Nx-1; ++i)
        u_new[i] = u[i] - CFL*(u[i+1]-u[i]);
    return u_new;
}

//Central
vector<double> central_space(const vector<double>& u) {
    vector<double> u_new = u;
    for(int i=1; i<Nx-1; ++i)
        u_new[i] = u[i] - CFL/2*(u[i+1] - u[i-1]);
    return u_new;
}