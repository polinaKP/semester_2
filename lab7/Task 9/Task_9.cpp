#include <iostream>

int main()
{
    int *a = new int[10000];
    int *a_ch = new int[10000];
    int *a_nech = new int[10000];
    for (int i = 0; i < 10000; ++i) {
        a[i] = 0;
    }
    int count_ch = 0;
    int count_nech = 0;
    int i = 0;
    while (std::cin >> a[i]){
        if (a[i] % 2 == 0) {
            a_ch[count_ch] = a[i];
            count_ch++;
        }else{
            a_nech[count_nech] = a[i];
            count_nech++;
        }
        i++;
    }

    for (int i = 1; i < count_ch; ++i)
        for (int j = i - 1; j >= 0; --j)
        if (a_ch[j] > a_ch[j + 1]){
            a_ch[j + 1] = a_ch[j + 1] - a_ch[j];
            a_ch[j] = a_ch[j] + a_ch[j + 1];
            a_ch[j + 1] = a_ch[j] - a_ch[j + 1];
        }

    for (int i = 0; i < count_ch; ++i)
        std::cout << a_ch[i] << ' ';

    for (int i = 1; i < count_nech; ++i)
        for (int j = i - 1; j >= 0; --j)
        if (a_nech[j] > a_nech[j + 1]){
            a_nech[j + 1] = a_nech[j + 1] - a_nech[j];
            a_nech[j] = a_nech[j] + a_nech[j + 1];
            a_nech[j + 1] = a_nech[j] - a_nech[j + 1];
        }
    for (int i = 0; i < count_nech; ++i)
        std::cout << a_nech[i] << ' ';

    delete [] a;
    delete [] a_ch;
    delete [] a_nech;
    return 0;
}
