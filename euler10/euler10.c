#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  long long MAX = 2000001;
  bool bool_array[MAX];
  memset(bool_array, true, MAX);

  for (int i = 2; i * i < MAX; i++) {
    if (bool_array[i]) {
      for (int j = i * i; j < MAX; j += i) {
        bool_array[j] = false;
      }
    }
  }

  long long sum_of_primes = 0;
  for (long long i = 2; i < MAX; i++) {
    if (bool_array[i])
      sum_of_primes += i;
  }

  printf("%lld", sum_of_primes);

  return 0;
}
