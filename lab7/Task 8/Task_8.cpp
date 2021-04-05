#include <iostream>

int get_distance(int *array, int N)
{
    int distance = N + 2;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (array[i] == - array[j] && array[i] < array[j] && j - i <= distance)
                distance = j - i;
        }
    }
    if (distance > N)
        return 0;
    else
        return distance;
}

int main()
{
    int N;
    std::cin >> N;
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> array[i];
    std::cout << get_distance(array, N) << '\n';
    return 0;
}
