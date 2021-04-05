#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int *lists = new int[100000];
    int size_list = 0;
    int a;
    std::cin >> a;
    while (a != 0)
    {
        lists[size_list] = a;
        size_list++;
        std::cin >> a;
    }
    double sum_X = 0.0;
    double sum_XX = 0.0;
    for (int i = 0; i < size_list; i++)
    {
        sum_X += lists[i];
        sum_XX += lists[i] * lists[i];
    }
    double M_X = sum_X / size_list;
    double M_XX = sum_XX / size_list;
    double D_X = M_XX - M_X * M_X;
    std::cout.precision(3);
    std::cout << std::fixed << M_X << ' ';
    std::cout << std::fixed << D_X;
    return 0;
}

