#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    int m;
    std::cin >> m;
    std::vector<std::string> word(m + 1);
    word[0] = "";
    for (int i = 1; i <= m; ++i)
        std::cin >> word[i];

    std::vector<int> d(m + 1, 0);

    d[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int length_max = 0;
        int el = 0;
        for (int k = 0; k < i; k++)
        {
            if (word[i].find(word[k]) == 0 && word[k].length() > length_max)
            {
                length_max = word[k].length();
                el = k;
            }
        }
        d[i] = length_max;
    }
    int max = 1;
    for (int i = 1; i < m; i++)
        if (d[max] < d[i + 1])
            max = i + 1;
    std::cout << '\n';
    std::cout << d[max] << '\n';
    return 0;
}
