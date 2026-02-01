#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include "Space_Scheme.h"
#include "Time_integrator.h"
#include "Parameters.h"

using namespace std;

void write_csv(const std::vector<double>& u, const std::string& filename) {
    mkdir("output", 0777);  
    std::string full_path = "output/" + filename;
    std::ofstream fout(full_path);
    for(size_t i = 0; i < u.size(); ++i) {
        double x = x_min + i*dx;   
        fout << x << "," << u[i] << "\n";
    }
    fout.close();
}

// Analytical solution
vector<double> initial_condition() {
    vector<double> u(Nx);
    for(int i=0; i<Nx; ++i){
        double x = x_min + i*dx;
        u[i] = exp(-200*(x-0.3)*(x-0.3));  // 高斯脉冲
    }
    return u;
}

vector<double> analytical_solution(double t) {
    vector<double> u(Nx);
    for(int i=0; i<Nx; ++i){
        double x = x_min + i*dx;
        double x_shift = x - a * t; 
        u[i] = exp(-200*(x_shift - 0.3)*(x_shift - 0.3));
    }
    return u;
}

int main() {
    vector<double> u0 = initial_condition();

    // Steps
    int Nt = static_cast<int>(t_end / dt);

    vector<double> u_up   = time_integrate(u0, upwind_space, Nt);
    vector<double> u_down = time_integrate(u0, downwind_space, Nt);
    vector<double> u_cen  = time_integrate(u0, central_space, Nt);
    vector<double> u_exact = analytical_solution(t_end);
    // Output
    write_csv(u0, "u0.csv");
    write_csv(u_up, "u_up.csv");
    write_csv(u_down, "u_down.csv");
    write_csv(u_cen, "u_central.csv");
    write_csv(u_exact, "u_exact.csv");
    cout << "Finish, The file is output" << endl;
    return 0;
}