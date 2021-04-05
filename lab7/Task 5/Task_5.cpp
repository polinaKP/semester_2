#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int *a = new int[n*n];
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = a + i*n;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];
    for (int j = 0; j < n; ++j) {
        for (int i = n - 1; i >= 0; --i)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    delete [] matrix;
    delete [] a;
    return 0;
}
