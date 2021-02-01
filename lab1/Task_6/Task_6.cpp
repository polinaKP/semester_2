#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++)
            if (j < i) {
                std::cout << ' ';
            }
            else {
                std::cout << "*";
            }
        std::cout << '\n';
    }
}
