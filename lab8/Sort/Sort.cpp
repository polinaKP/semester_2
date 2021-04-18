#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <string>

void bubble(int *sort_list_start, int N)
{
    int *sort_list = new int[N];
    for (int i = 0; i < N; ++i)
        sort_list[i] = sort_list_start[1];

    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
        if (sort_list[j] > sort_list[i]){
            sort_list[i] = sort_list[i] - sort_list[j];
            sort_list[j] = sort_list[j] + sort_list[i];
            sort_list[i] = sort_list[j] - sort_list[i];
        }
}

void selection(int *sort_list_start, int N)
{
    int *sort_list = new int[N];
    for (int i = 0; i < N; ++i)
        sort_list[i] = sort_list_start[1];

    int max_el = sort_list[0];
    int k = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N - i; ++j)
        if (sort_list[j] > max_el) {
            max_el = sort_list[j];
            k = j;
        }
        sort_list[k] = sort_list[N - i - 1];
        sort_list[N - i - 1] = max_el;
        max_el = sort_list[0];
        k = 0;
    }
}

void insertion(int *sort_list_start, int N)
{
    int *sort_list = new int[N];
    for (int i = 0; i < N; ++i)
        sort_list[i] = sort_list_start[1];

    for (int i = 1; i < N; ++i)
        for (int j = i - 1; j >= 0; --j)
        if (sort_list[j] > sort_list[j + 1]){
            sort_list[j + 1] = sort_list[j + 1] - sort_list[j];
            sort_list[j] = sort_list[j] + sort_list[j + 1];
            sort_list[j + 1] = sort_list[j] - sort_list[j + 1];
        }
}

void Shell(int *sort_list_start, int N)
{
    int *sort_list = new int[N];
    for (int i = 0; i < N; ++i)
        sort_list[i] = sort_list_start[1];

    int *step_list = new int[N / 2];
    step_list[0] = 1;
    for (int i = 1; i < N / 2; ++i)
        step_list[i] = 0;
    int step = 5;
    int i = 1;
    int step_count = 1;
    while (N > step)
    {
        step_list[i] = step;
        i++;
        if (i % 2 == 0)
            step = 9 * pow(2, i) - 9 * pow(2, (i/2)) + 1;
        else
            step = 8 * pow(2, i) - 6 * pow(2, ((i + 1)/2)) + 1;
        step_count++;
    }

    int d = step_list[step_count];
    while (step_count >= 0){
        for (int i = 0; i < N - d; i++){
            int j = i;
            while (j >= 0 && sort_list[j] > sort_list[j+d]){
                int count = sort_list[j];
                sort_list[j] = sort_list[j+d];
                sort_list[j+d] = count;
                j--;
            }
        }
        step_count--;
        d = step_list[step_count];
    }
}

void write_file(int time, int N, const std::string file)
{
    std::ofstream output;
    output.open(file, std::ios::app);
    if (output.is_open()){
        output << N << "; " << time << ";" << '\n';
        output.close();
    }
}

void get_time(int *sort_list, int N, int repeat)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= repeat; i++)
        selection(sort_list, N);
    auto end = std::chrono::high_resolution_clock::now();

    auto delta_start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= repeat; i++) {
        int *sort_list_start = new int[N];
        for (int i = 0; i < N; ++i)
            sort_list_start[i] = sort_list[1];
        delete [] sort_list_start;
    }
    auto delta_end = std::chrono::high_resolution_clock::now();

    auto nsec = end - start - (delta_end - delta_start);
    int time = nsec.count() / repeat;
    std::cout << time << " ns." << std::endl;
    write_file(time, N, "time_file_selection.txt");
}

int main() {
    std::mt19937 engine(23);
    std::uniform_int_distribution<int> int_dist(0, 10);
    int N = 1000;
    int *sort_list = new int[N];
    for (int i = 0; i < N; ++i){
        sort_list[i] = int_dist(engine);
    }
    std::cout << '\n';
    int repeat = 1;

    for (int i = 20000; i <= 200000; i = i + 20000)
        get_time(sort_list, i, repeat);

 return 0;
}
