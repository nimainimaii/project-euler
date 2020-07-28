#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

// function to repalce a digit at a positon(0-indexed from right) in original_number with new_digit
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

// calculates number of digits
int num_of_digits(int number) {
    int number_of_digits = 0;
    while (number != 0) {
        number /= 10;
        number_of_digits++;
    }
    return number_of_digits;
}

// takes in integer and returns vector with values containing indices which are TRUE for binary representation of number
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

// check for prime numbers by replacing digits at positions given by indices with digits 0-9
// counter gets incremented when prime number is generated
// returns smallest prime from generated list IF number of primes is 8, otherwise returns -1
int check_specific_pattern(int prime, bool* bool_array, std::vector<int> indices) {
    int store;
    int counter = 0;
    std::vector<int>::iterator index_iter = indices.begin();
    int start = 0;
    if (indices.back() == num_of_digits(prime) - 1) {
        start = 1;
    }
    for (int i = start; i < 10; i++, index_iter = indices.begin()) {
        int new_number = prime;
        while (index_iter != indices.end()) {
            new_number = replace_digit(new_number, *index_iter, i);
            index_iter++;
        }
        if (bool_array[new_number] && counter == 0) {
            store = new_number;
        }
        if (bool_array[new_number]) counter++;
    }
    return counter == 8 ? store : -1;
}

// invoke check_specific_pattern function using possible combinations of digits to replace
// see get_indices function to see how digit combinations are created
int check_pattern(int prime, bool* bool_array) {
    int number_of_digits = num_of_digits(prime);
    for (int i = 1; i < pow(2, number_of_digits) - 1; i++) {
        int check = check_specific_pattern(prime, bool_array, get_indices(i));
        if (check != -1) return check;
    }
    return -1;
}

int main() {
    int MAX = 2000000;
    bool bool_array[MAX];
    memset(bool_array, true, MAX);

    // Prime number algorithm (Erasthoneses Seive)
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
        int check = check_pattern(*prime, bool_array);
        if (check != -1) {
            std::cout << check << std::endl;
            break;
        }
    }
    return 0;
}
