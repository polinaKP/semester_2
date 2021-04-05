#include <iostream>

int main() {
    int N, a, k;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> a;
        int b = a;
        while (b / 10 != 0)
            b /= 10;
        if (((a % 4 == 0) && b != 4 && b != 5) || ((a % 7 == 0) && b != 7 && b != 1) || ((a % 9 == 0) && b != 9 && b != 8))
            std::cout << a << '\n';
        else
            k++;
    }
    if (k == N)
        std::cout << 0;
    return 0;
}
