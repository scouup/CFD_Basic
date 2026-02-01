 #include "Time_integrator.h"

vector<double> time_integrate(vector<double> u0, SpatialFunc space_scheme, int Nt) {
    vector<double> u = u0;
    for(int n=0; n<Nt; ++n) {
        u = space_scheme(u);
    }
    return u;
}
