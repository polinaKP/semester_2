#include <iostream>

int main() {
    int a, b, c, d, x;
    int mark = 2;
    std::cin >> a >> b >> c >> d >> x;
    int x_1 = b - a;
    int x_2 = d / c;
    if (x == x_1 && x == x_2)
        mark = 5;
    else if (x == x_1 || x == x_2)
        mark = 4;
    else if (x == 1024)
        mark = 3;
    std::cout << mark;
    return 0;
}
