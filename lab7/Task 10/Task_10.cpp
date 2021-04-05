#include <iostream>

int get_digit(int element, int digit)
{
    for (int i = 1; i < digit; i++)
        element /= 10;
    return element % 10;
}

int *get_sort(int *array, int digit, int count)
{
    for (int i = 1; i < count; ++i)
        for (int j = i - 1; j >= 0; --j){
        int a_i = get_digit(array[j + 1], digit);
        int a_j = get_digit(array[j], digit);
        if (a_j > a_i){
            array[j + 1] = array[j + 1] - array[j];
            array[j] = array[j] + array[j + 1];
            array[j + 1] = array[j] - array[j + 1];
        }
        }
    return array;
}

int digit_max(int *array, int count)
{
    int max = array[0];
    for (int i = 1; i < count; i++)
        if (array[i] > max)
            max = array[i];
    int digit_count = 0;
    while (max != 0)
    {
        digit_count++;
        max /= 10;
    }
    return digit_count;
}

int main()
{
    int *array = new int[10000];
    int count = 0;
    while (std::cin >> array[count]){
        count++;
    }
    int max = digit_max(array, count);
    for (int i = 1; i <= max; i++){
        array = get_sort(array, i, count);
        for (int j = 0; j < count; j++)
            std::cout << array[j] << ' ';
        std::cout << '\n';
    }
    delete [] array;
}
