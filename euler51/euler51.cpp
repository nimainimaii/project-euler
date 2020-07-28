#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

int replace_digit(int original_number, int position, int new_digit) {
    int new_number;
    int archive = original_number;
    int old_digit;
    for (int i = 0; i <= position; i++) {
        old_digit = original_number % 10;
        original_number /= 10;
    }
    original_number = archive;
    new_number = original_number + (new_digit - old_digit) * pow(10, position);
    return new_number;
}

int num_of_digits(int number) {
    int number_of_digits = 0;
    while (number != 0) {
        number /= 10;
        number_of_digits++;
    }
    return number_of_digits;
}

std::vector<int> get_indices(int number) {
    bool binary[32];
    memset(binary, false, 32);
    int k = 0;
    while (number != 0) {
        binary[k] = number % 2;
        number /= 2;
        k++;
    }
    std::vector<int> indices;
    for (int i = 0; i < 32; i++) {
        if (binary[i]) {
            indices.push_back(i);
        }
    }
    return indices;
}

bool check_specific_pattern(int prime, bool* bool_array, std::vector<int> indices) {
    int counter = 0;
    std::vector<int>::iterator index_iter = indices.begin();
    for (int i = 0; i < 10; i++, index_iter = indices.begin()) {
        int new_number = prime;
        while (index_iter != indices.end()) {
            new_number = replace_digit(new_number, *index_iter, i);
            index_iter++;
        }
        if (bool_array[new_number]) counter++;
    }

    return counter == 8;
}

bool check_pattern(int prime, bool* bool_array) {
    int number_of_digits = num_of_digits(prime);
    for (int i = 0; i < pow(2, number_of_digits); i++) {
        std::vector<int> indices = get_indices(i);
        bool check = check_specific_pattern(prime, bool_array, indices);
        if (check) return true;
    }
    return false;
}

int main() {
    int MAX = 2000000;
    bool bool_array[MAX];
    memset(bool_array, true, MAX);

    for (int i = 2; i * i < MAX; i++) {
        if (bool_array[i]) {
            for (int j = i * i; j < MAX; j += i) {
                bool_array[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i < MAX; i++) {
        if (bool_array[i]) primes.push_back(i);
    }

    std::vector<int>::iterator prime = primes.begin();
    for (; prime != primes.end(); prime++) {
        if (check_pattern(*prime, bool_array)) {
            std::cout << *prime << std::endl;
        }
    }

    return 0;
}
