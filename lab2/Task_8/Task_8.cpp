#include <iostream>

int main()
{
    int N;
    int i = 2;
    std::cin >> N;
    while (N != 1) {
        if (N % i == 0) {
            std::cout << i << '\n';
            N /= i;
        }
        if (N % i != 0)
            i++;
    }
}
