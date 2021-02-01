#include <iostream>

int main()
{
    std::double leg1;
    std::double leg2;
    std::double hypotenuse;
    std::cin >> leg1;
    std::cin >> leg2;
    hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2)
    std::cout << hypotenuse << std::endl;
    return 0;
}
