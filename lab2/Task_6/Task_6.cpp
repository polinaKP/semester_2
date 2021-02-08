#include <iostream>

int main()
{
    int a;
    int max_el = 0;
    int k = 0;
    std::cin >> a;
    while (a != 0) {
        if (a > max_el) {
            max_el = a;
            k = 0;
        }
        if (a == max_el)
            k += 1;
        std::cin >> a;
    }
    std::cout << k;
}
