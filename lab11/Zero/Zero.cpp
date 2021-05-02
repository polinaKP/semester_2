#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char const *argv[])
{
    int N, K;
    std::cin >> N >> K;

    int el_1, el_2, count = 0;
    for (int number_1 = pow(K, N - 1); number_1 < pow(K, N); number_1++)
    {
        int number = number_1;
        el_1 = number - number / K * K;
        number /= K;
        while(number > 0)
        {
            std::cout << el_1 << ' ';
            el_2 = el_1;
            el_1 = number - number / K * K;
            number /= K;
            if (el_1 == 0 && el_2 == 0)
                break;
        }
        std::cout << '\n';
        if (number == 0 && (el_1 != 0 || el_2 != 0))
            count++;
    }
    std::cout << count << '\n';
    return 0;
}
