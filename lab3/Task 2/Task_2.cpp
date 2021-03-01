#include <iostream>

int main()
{
    int n,m,x;
    std::cin >> n >> m >> x;
    int *a = new int[n*m];
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = a + i*m;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matrix[i][j] = 0;
    for (int k = 0; k < x; ++k) {
        int i,j;
        std::cin >> i >> j;
        matrix[i - 1][j - 1] = -1;
        for (int y = 0; y <= 2; ++y)
            for (int z = 0; z <= 2; ++z)
                if ((i + y >= 2) && (i + y < n + 2) && (j + z >= 2) && (j + z < m + 2)
                    && (matrix[i - 2 + y][j - 2 + z] != -1))
                    matrix[i - 2 + y][j - 2 + z] += 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
    delete [] matrix;
    delete [] a;
    return 0;
}
