#include <iostream>

int main()
{
    int sum = 0;
    int n;
    std::cin >> n;
    int * a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > (sum / n))
            k += a[i];
    }
    std::cout << k;
    delete [] a;
}
