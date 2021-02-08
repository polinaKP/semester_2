#include <iostream>

int main()
{
    int a;
    int k = 0;
    std::cin >> a;
    while (a != 0) {
        if (a % 2 == 0)
            k += 1;
        std::cin >> a;
    }
    std::cout << k;
}
