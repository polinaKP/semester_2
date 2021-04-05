#include <iostream>
#include <cmath>

double f(double x)
{
    return x;
}

double find_root(double f(double), double a, double b, double tol)
{
    double eps = 0.000001;
    double c = (a + b)/2;
    if ((std::abs(a - b) <= tol) || ((std::abs(f(c)) <= eps))){
        return c;
    }
    if (f(c) * f(a) < 0)
        find_root(f, a, c, tol);
    else
        find_root(f, c, b, tol);
}

int main()
{
    std::cout << find_root(f, -1, 2, 0.000001);
}
