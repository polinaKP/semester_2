#include <iostream>
#include <string>
#include <cmath>

int main() {
    int N, news;
    std::cin >> N >> news;
    std::string *str_list = new std::string[N + 1];
    int *true_list = new int[N];
    std::string str;
    int a;
    for (int i = 0; i < N; i++)
    {
        std::cin >> str >> a;
        str_list[i] = str;
        true_list[i] = a;
    }
    str_list[N] = "0";
    int M;
    std::cin >> M;

    int j = 0;
    int k = 1;
    int f = 0;
    int news_head = news;
    bool flag = true;
    while (k != M + 1)
    {
        if (true_list[j] == 0 && news_head == 1)
            news_head = abs(news_head - 1);
        else if (true_list[j] == 0 && news_head == 0){
            news_head = abs(news_head - 1);
            true_list[j] = 1;
        }
        else if (true_list[j] == 1 && news_head == 0)
            str_list[j] = "0";
        if (str_list[j+1] == "0"){
            f = j;
            while (str_list[j+1] == "0" && j != N - 1)
                j++;
            if (j == N - 1){
                j = 0;
                if (str_list[j] == "0")
                    while (str_list[j] == "0" && j != N - 1)
                        j++;
            if (f == j)
                break;
            }
            }
        else j++;
        k++;
    }
    for (int i = 0; i < N; i++)
    {
        if (str_list[i] != "0")
            std::cout << str_list[i] << ' ' << true_list[i] << '\n';
    }
    return 0;
}
