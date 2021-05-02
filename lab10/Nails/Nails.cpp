#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int N;
    std::cin >> N;
    std::vector<int> coord(N + 1);
    coord[0] = 0;
    for (int i = 1; i <= N; ++i)
        std::cin >> coord[i];

    std::vector<int> d(N + 1);

    d[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        d[i] = std::min(coord[i] - coord[i - 1] + d[i - 2], coord[i] - coord[i - 1] + d[i - 1]);
        std::cout << d[i] << " ";
    }

    std::cout << d[N] << '\n';
    return 0;
}
