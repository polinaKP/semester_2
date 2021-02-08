#include <iostream>

int main()
{
    int a;
    int flag = 1;
    std::cin >> a;
    for (int i = 2; i < a - 1; i++)
        if (a % i == 0) {
            flag = 0;
            break;
        }
    std::cout << flag;
}
