#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// function for replacing digit at index, position is zero-indexed from the
// right
long long replace_digit(long long original_number, int position, int new_digit) {
    long long new_number;
    long long archive = original_number;

    int old_digit;
    for (int i = 0; i <= position; i++) {
        old_digit = original_number % 10;
        original_number /= 10;
    }
    original_number = archive;

    new_number = original_number + (new_digit - old_digit) * pow(10, position);

    return new_number;
}

int num_of_digits(long long number) {
    int number_of_digits = 0;
    while (number != 0) {
        number /= 10;
        number_of_digits++;
    }
    return number_of_digits;
}

bool check_specific_pattern(long long prime, int* indices, int num_of_indices, int number_of_digits, bool* bool_array) {
    int* index_iterator = indices;
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        long long new_number = prime;
        while (index_iterator != indices + num_of_indices) {
            new_number = replace_digit(new_number, *index_iterator, i);
            index_iterator++;
        }
        if (bool_array[new_number]) {
            counter++;
        }
        index_iterator = indices;
    }

    return counter == 7;
}

bool check_pattern(long long prime, bool* bool_array) {
    // int counter = 0;
    // for (int i = 0; i < 10; i++) {
    //     long long new_number = replace_digit(prime, 1, i);
    //     new_number = replace_digit(new_number, 2, i);
    //     if (bool_array[new_number]) {
    //         counter++;
    //     }
    // }
    // return counter == 7;

    int number_of_digits = num_of_digits(prime);
    int indices[] = {1, 2};
    return check_specific_pattern(prime, indices, 2, number_of_digits, bool_array);
}

int main() {
    long long MAX = 2000000;
    bool bool_array[MAX];
    memset(bool_array, true, MAX);

    for (int i = 2; i * i < MAX; i++) {
        if (bool_array[i]) {
            for (int j = i * i; j < MAX; j += i) {
                bool_array[j] = false;
            }
        }
    }

    // count number of primes calculated
    int number_of_primes = 0;
    for (bool* ptr = bool_array; ptr != bool_array + MAX; ptr++) {
        if (*ptr) number_of_primes++;
    }

    // fill primes array from bool_array
    long long primes[number_of_primes];
    int counter = 0;
    for (int i = 2; i < MAX; i++) {
        if (bool_array[i]) {
            primes[counter] = i;
            counter++;
        }
    }

    // check all primes for condition
    /*for (long long* prime = primes; prime != primes + number_of_primes; prime++) {*/
        /*if (check_pattern(*prime, bool_array)) {*/
            /*printf("%lld", *prime);*/
            /*break;*/
        /*}*/
        /*printf("%d", check_pattern(*prime, primes, bool_array, number_of_primes));*/
    /*}*/

    int indices[] = {1,2};
    int an = check_specific_pattern(56003, indices, 2, 5, bool_array);
    printf("%d", an);

    return 0;
}
