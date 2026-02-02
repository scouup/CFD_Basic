#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <cmath>
#include "Parameters.h"
#include "Time_integrator.h"

using namespace std;

void write_csv(const vector<double>& psi, const string& filename){
    ofstream fout(filename);
    for(int i = 0; i < Nx; ++i){
        double x = x_min + i*dx;
        fout << x << "," << psi[i] << "\n";
    }
    fout.close();
}

vector<double> initial_condition(){
    vector<double> psi(Nx,0.0);
    double sigma = 100.0;  
    for(int i = 0; i < Nx; ++i){
        double x = x_min + i*dx;
        psi[i] = exp(-sigma * x*x);
    }
    return psi;
}

vector<double> analytical_solution(double t){
    vector<double> psi(Nx, 0.0);
    for(int i = 0; i < Nx; ++i){
        double x = x_min + i * dx;

        double right = exp(-100.0 * pow(x - (U + c0)*t, 2));
        double left  = exp(-100.0 * pow(x - (U - c0)*t, 2));

        psi[i] = 0.5 * (right + left);
    }
    return psi;
}

int main(){
    mkdir(output_dir.c_str(), 0777);

    vector<double> psi0 = initial_condition();
    vector<double> psi_final(Nx,0.0);

    int Nt = static_cast<int>(t_end/dt);

    time_integrate(psi0, Nt, psi_final,
        [](const vector<double>& psi_num, int step){
            if(step % output_interval == 0){
                string fnum = output_dir + "/psi_step_" + to_string(step) + ".csv";
                write_csv(psi_num, fnum);
                double t = step * dt;
                vector<double> psi_exact = analytical_solution(t);
                string fexact = output_dir + "/psi_analytical_step_" + to_string(step) + ".csv";
                write_csv(psi_exact, fexact);
            }
        }
    );

    cout << "Finished. Output every " << output_interval << " steps in " << output_dir << endl;
    return 0;
}
