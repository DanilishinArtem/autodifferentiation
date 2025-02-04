#include "src/dual.h"


int main(){
    double x0 = 1.0;
    
    Dual<double> x(x0, 1.0);
    Dual<double> f = sin(x) + x * exp(log(sin(x)));

    std::cout << "f(" << x0 << ") = " << f.value << std::endl;
    std::cout << "f'(" << x0 << ") = " << f.derivative << std::endl;
    return 0;
}