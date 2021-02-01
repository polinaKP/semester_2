#include <iostream>
#include <cmath>

int main()
{
    double leg1;
    double leg2;
    double hypotenuse;
    std::cin >> leg1;
    std::cin >> leg2;
    hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2);
    std::cout << hypotenuse << std::endl;
    return 0;
}
