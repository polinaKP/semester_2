#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = N - i; j > 0; j--)
            std::cout << "*" << ' ';
        std::cout << '\n';
    }
}
