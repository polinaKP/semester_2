#include <iostream>

int main()
{
    int a;
    int b;
    std::cin >> a >> b;
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    int k = a | b;
    std::cout << k;
}
