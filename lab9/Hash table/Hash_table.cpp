#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

struct Node
{
    int value;
    int key;
    bool is_used = false;
    bool was_used = false;
};

struct Hash
{
    Node *array;
    size_t size;
    size_t used_amount;
    double used_ratio = 0;
};

int get_prime(size_t size)
{
    int prime = size - 2;
    int min = std::min(prime, (int)size);
    int max_div = std::sqrt(min);
    int div = 2;
    while (prime > 0 && div <= max_div){
        while (div <= max_div && (prime % div) * (size % div) != 0){
            div ++;
        }
        prime --;
    }
    if (prime == 0){
        prime = size - 1;
    }
    return prime;
}

Hash *permutation(Hash *hash)
{
    size_t new_size = hash->size * 2;
    Node *new_array = new Node[new_size];
    for (int index = 0; index < hash->size; index ++){
        if (hash->array[index].is_used){
            int new_index = ((hash->array[index].key) * (new_size - 1)) % new_size;
            if (new_array[new_index].is_used){
                int new_prime = get_prime(new_size);
                int key = hash->array[index].key;
                int index_delta = (key * new_prime) % new_size;
                while (new_array[new_index].is_used){
                    new_index = new_index + index_delta;
                }
            }
            new_array[new_index].value = hash->array[index].value;
            new_array[new_index].key = hash->array[index].key;
            new_array[new_index].is_used = true;
            new_array[new_index].was_used = true;
        }
    }
    delete[] hash->array;
    hash->array = new_array;
    hash->size = new_size;
    hash->used_ratio = hash->used_amount / hash->size;
    return hash;
}

Hash *push(Hash *hash, int value, int key)
{
    int prime = hash->size - 1;
    int index = (key * prime) % hash->size;
    if (hash->array[index].is_used){
        int new_prime = get_prime(hash->size);
        int index_delta = (key * prime) % hash->size;
        while (hash->array[index].is_used){
            index = (index + index_delta) % hash->size;
        }
    }
    hash->array[index].value = value;
    hash->array[index].key = key;
    hash->array[index].is_used = true;
    hash->array[index].was_used = true;
    hash->used_amount++;
    hash->used_ratio = (double)hash->used_amount / (double)hash->size;
    if (hash->used_ratio > 0.5){
        hash = permutation(hash);
    }
    return hash;
}

Hash *create_hash(size_t size)
{
    Hash *hash = new Hash;
    hash->array = new Node[1];
    hash->size = 1;
    hash->used_amount = 0;
    int value;
    for (int key = 0; key < size; key ++){
        value = key;
        hash = push(hash, value, key);
    }
    return hash;
}

int find_value(Hash* hash, int key)
{
    int prime = hash->size - 1;
    int index = (key * prime) % hash->size;
    if (hash->array[index].was_used){
        if (hash->array[index].key != key){
            int new_prime = get_prime(hash->size);
            int index_delta = (key * new_prime) % hash->size;
            while (hash->array[index].key != key && hash->array[index].was_used){
                index = (index + index_delta) % hash->size;
            }
        }
        if (hash->array[index].was_used){
            if (hash->array[index].is_used){
                return hash->array[index].value;
            }
            else return INT_MIN;
        }
        else return INT_MIN;
    }
    else return INT_MIN;
}

int pop(Hash* hash, int key)
{
    int prime = hash->size - 1;
    int index = (key * prime) % hash->size;
    if (hash->array[index].was_used){
        if (hash->array[index].key != key){
            int new_prime = get_prime(hash->size);
            int index_delta = (key * new_prime) % hash->size;
            while (hash->array[index].was_used && hash->array[index].key != key){
                index = (index + index_delta) % hash->size;
            }
        }
        if (hash->array[index].was_used){
            if (hash->array[index].is_used){
                hash->array[index].is_used = false;
                hash->used_amount --;
                hash->used_ratio = (double)hash->used_amount / (double)hash->size;
                return hash->array[index].value;
            }
            else return INT_MIN;
        }
        else return INT_MIN;
    }
    else return INT_MIN;
}

int get_time(int find(Hash*, int), Hash* hash, int key, const int repeat_amount)
{
    const auto start = std::chrono::high_resolution_clock::now();
    for (int repeat = 0; repeat < repeat_amount; repeat++){
        int value = find(hash, key);
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto delta_time = end - start;
    const int time = delta_time.count();
    const int single_call_time = time / repeat_amount;
    return single_call_time;
}

void write_file(const size_t size, const int time, const std::string path)
{
    std::ofstream output;
    output.open(path, std::ios::app);
    if (output.is_open()){
        output << size << "; " << time << " ns;" << '\n';
        output.close();
    }
}

void delete_hash(Hash* hash)
{
    delete[] hash->array;
    delete[] hash;
}

void make_test(const size_t size_start, const size_t size_finish, const double step, const std::string path)
{
    const int amount = 10000000;
    for (size_t size = size_start; size <= size_finish; size = size * step){
        int time_min = -1;
        Hash* hash = create_hash(size);
        int key = size / 2;
        const int time = get_time(find_value, hash, key, amount);
        delete_hash(hash);
        if (time > 0){
            if (time < time_min || time_min == -1){
                time_min = time;
            }
        }
        write_file(size, time_min, path);
        std::cout << "Size: " << size << ";" << '\n';
    }
}

void clear_file(const std::string path)
{
    std::ofstream output;
    output.open(path);
    if (output.is_open()){
        output.close();
    }
}

int main()
{
    const size_t size_start = 1, size_finish = 10000;
    const double step = 2;
    const std::string path = "hash_table.txt";
    clear_file(path);
    make_test(size_start, size_finish, step, path);
    return 0;
}
