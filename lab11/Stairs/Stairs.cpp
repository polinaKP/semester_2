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

    std::vector<int> d(N + 1, 0);
    std::vector<int> p(N + 1, 0);

    d[0] = 0;
    p[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
        if (i == 1)
            d[i] = coord[i];
        else if (coord[i] + d[i - 1] > coord[i] + d[i - 2])
                d[i] = coord[i] + d[i - 1];
        else
            {
                d[i] = coord[i] + d[i - 2];
                p[i - 1] = 0;
                p[i - 2] = i - 2;
            }
    }
    std::cout << d[N] << '\n';
    for (int i = 1; i <= N; i++)
    {
        if (p[i] != 0)
            std::cout << i << ' ';
    }
    return 0;
}
