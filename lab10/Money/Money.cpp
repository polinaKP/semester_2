#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    int S, N;
    std::cin >> S >> N;
    std::vector<int> money(N + 1);
    money[0] = 0;
    for (int i = 1; i <= N; ++i)
        std::cin >> money[i];

    std::vector< std::vector<int> > d(S + 1, std::vector<int>(N + 1, 0));

    for (int i = 1; i <= S; i++)
    {
        d[i][0] = S + 1;
        for (int j = 1; j <= N; j++)
        {
            if (money[j] <= i)
                d[i][j] = std::min(d[i - money[j]][j] + 1, d[i][j - 1]);
            else d[i][j] = std::min(d[i - 1][j] + 1, d[i][j - 1]);
            std::cout << d[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << d[S][N] << '\n';
    return 0;
}
