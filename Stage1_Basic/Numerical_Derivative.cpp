// In this case, we just want to do some basic things. 
// To do the numerical derivative, include Upwind, downwind,and central
// The case is easy, but it can represent some thing.

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // Mesh parameter
    int N = 21;
    double xmin = 0.0;
    double xmax = 1.0;
    double dx = (xmax - xmin) / (N-1);

    //
    std::vector<double> x(N);
    std::vector<double> u(N);
    std::vector<double> dudx(N);

    // Initialize
    for (int i = 0; i < N; ++i){
        x[i] = xmin + i*dx; 
        u[i] = x[i] * x[i];
    }
    // Central
    for (int i = 0; i<N-1; ++i){
        dudx[i] = (u[i+1] - u[i-1])/2.0/dx;
    }

    dudx[0] = 0.0;
    dudx[N-1] = 2.0 * x[N-1];

    //Output
    std::cout << "x     Numerical       Exact\n";
    for (int i = 0; i < N; ++i){
        std::cout << x[20] << "      "
                  << dudx[i] << "       "
                  << 2.0 * x[i] << std::endl;
    }
}