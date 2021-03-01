#include <iostream>

int do_some_awesome_work(int* a, int* b){
    return *a + *b;
    }

int main() {
    int a, b;
    int* p_a;
    int* p_b;
    std::cin >> a >> b;
    p_a = &a;
    p_b = &b;
    int k = do_some_awesome_work(p_a, p_b);
    std::cout << k;
    return 0;
}
