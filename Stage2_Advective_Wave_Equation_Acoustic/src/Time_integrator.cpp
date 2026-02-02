#include "Time_integrator.h"
#include "Parameters.h"

void time_integrate(
    const vector<double>& psi0,
    int Nt,
    vector<double>& psi_final,
    function<void(const vector<double>&, int)> write_callback
){
    vector<double> psi_old = psi0;   
    vector<double> psi     = psi0;   
    vector<double> psi_new(Nx, 0.0);   

    double alpha = dt / (2.0 * dx);
    double beta  = (dt*dt) / (dx*dx) * (c0*c0 - U*U);

    for(int n = 1; n <= Nt; ++n){
        for(int i = 1; i < Nx-1; ++i){
            double conv = U * alpha * (psi[i+1] - psi[i-1] - psi_old[i+1] + psi_old[i-1]);
            double wave = beta * (psi[i+1] - 2.0*psi[i] + psi[i-1]);
            psi_new[i] = 2.0*psi[i] - psi_old[i] - conv + wave;
        }

        psi_new[0]    = 0.0;
        psi_new[Nx-1] = 0.0;

        psi_old = psi;
        psi     = psi_new;

        if(write_callback) write_callback(psi, n); 
    }

    psi_final = psi;
}
