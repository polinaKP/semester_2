#include <iostream>

int main()
{
    int a;
    int max_el = 0;
    std::cin >> a;
    while (a != 0) {
        if (a % 2 == 0 && a >= max_el)
            max_el = a;
        std::cin >> a;
    }
    std::cout << max_el;
}
