#include <iostream>
#include <string>
#include <cmath>

std::string fun(int b) {
    std::string str = "";
    while (b > 9) {
        str += "<";
        b -= 10;
    }
    while (b > 0) {
        str += "v";
        b -= 1;
    }
    return str;
}

int main()
{
    int a;
    std::string str = "";
    std::cin >> a;
    while (a > 0) {
        int b = floor(a / 60);
        a -= b * 60;
        str = "." + fun(a) + str;
        a = b;
    }
    str.replace(0, 1, "");
    std::cout << str;
}
