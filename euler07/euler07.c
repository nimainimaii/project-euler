#include <stdbool.h>
#include <stdio.h>
#include <string.h>

long long nth_prime(int n) {
  long long MAX = 1000000;
  bool bool_array[MAX];

  /*for (bool *p = bool_array; p != bool_array + MAX; p++) {*/
  /**p = true;*/
  /*}*/

  memset(bool_array, true, sizeof(bool_array));

  for (long long i = 2; i * i < MAX; i++) {
    if (bool_array[i]) {
      for (long long j = i * i; j < MAX; j += i) {
        bool_array[j] = false;
      }
    }
  }

  int number_of_primes_cal = 0;
  for (long long i = 2; i < MAX; i++) {
    if (bool_array[i])
      number_of_primes_cal++;
  }

  long long primes[number_of_primes_cal];
  int index = 0;
  for (int i = 2; i < MAX; i++) {
    if (bool_array[i]) {
      primes[index] = i;
      index++;
    }
  }

  return primes[n - 1];
}

int main() {
  printf("%lld", nth_prime(10001));
  return 0;
}
