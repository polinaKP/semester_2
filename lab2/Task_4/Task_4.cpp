#include <iostream>
#include <cmath>

int main()
{
    double N;
    std::cin >> N;
    while (N > 1) {
        N /= 2;
    }
    if (N == 1)
        std::cout << "YES";
    else
        std::cout << "NO";
}
