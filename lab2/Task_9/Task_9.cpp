#include <iostream>

int main()
{
    std::string n;
    int speed;
    int k = 0;
    std::cin >> speed >> n;
    while (n != "A999AA") {
        if (n[1] == n[2] && n[1] == n[3] && speed > 60)
            k += 1000;
        else if ((n[1] == n[2] || n[1] == n[3] || n[2] == n[3]) && speed > 60)
                 k += 500;
        else if (speed > 60)
                 k += 100;
        std::cin >> speed >> n;
    }
    std::cout << k;
}
