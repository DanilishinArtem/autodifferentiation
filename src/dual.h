#ifndef DUAL
#define DUAL

#include <iostream>
#include <cmath>

template<typename T>
class Dual
{
public:
    T value;
    T derivative;

    Dual(T value = 0, T derivative = 0) : value(value), derivative(derivative) {};
};

template<typename T>
Dual<T> operator+(const Dual<T>& a, const Dual<T>& b)
{
    return Dual<T>(a.value + b.value, a.derivative + b.derivative);
}

template<typename T>
Dual<T> operator-(const Dual<T>& a, const Dual<T>& b)
{
    return Dual<T>(a.value - b.value, a.derivative - b.derivative);
}

template<typename T>
Dual<T> operator*(const Dual<T>& a, const Dual<T>& b)
{
    // (a * b)' = a' * b + a * b'
    return Dual<T>(
        a.value * b.value,
        a.derivative * b.value + a.value * b.derivative
    );
}

template<typename T>
Dual<T> operator/(const Dual<T>& a, const Dual<T>& b)
{
    // (a / b)' = (a' * b - a * b') / b^2
    return Dual<T>{
        a.value / b.value,
        (a.derivative * b.value - a.value * b.derivative) / b.value / b.value
    };
}



template<typename T>
Dual<T> sin(const Dual<T>& a)
{
    // (sin(x))' = cos(x)
    return Dual<T>(std::sin(a.value), std::cos(a.value) * a.derivative);
}

template<typename T>
Dual<T> cos(const Dual<T>& a)
{
    // (cos(x))' = -sin(x)
    return Dual<T>(std::cos(a.value), -std::sin(a.value) * a.derivative);
}

template<typename T>
Dual<T> exp(const Dual<T>& a)
{
    // (exp(x))' = exp(x)
    T exp_val = std::exp(a.value);
    return Dual<T>(exp_val, exp_val * a.derivative);
}

template<typename T>
Dual<T> log(const Dual<T>& a)
{
    // (log(x))' = 1 / x
    return Dual<T>(std::log(a.value), a.derivative / a.value);
}


#endif