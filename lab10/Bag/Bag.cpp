#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int W, N;
    std::cin >> W >> N;
    std::vector<int> price(N + 1);
    std::vector<int> weight(N + 1);
    price[0] = 0;
    weight[0] = 0;
    for (int i = 1; i <= N; ++i)
        std::cin >> price[i];
    for (int i = 1; i <= N; ++i)
        std::cin >> weight[i];

    std::vector< std::vector<int> > d(W + 1, std::vector<int>(N + 1, 0));

    for (int i = 1; i <= W; i++)
    {
        d[i][0] = 0;
        for (int j = 1; j <= N; j++)
        {
            if (weight[j] <= i)
                d[i][j] = std::max(d[i - weight[j]][j - 1] + price[j], d[i][j - 1]);
            else d[i][j] = d[i][j - 1];
            std::cout << d[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << d[W][N] << '\n';
    return 0;
}
