#include <stdio.h>

int sum_of_squares_upto(int n) {
    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
        sum += i*i;
    }
    return sum;
}

int sum_upto(int n) {
    return n*(n+1) / 2;
}

int result(int n) {
  int sum1 = sum_upto(n);
  sum1 *= sum1;

  int sum2 = sum_of_squares_upto(n);

  return sum1 - sum2;
}

int main() {
    printf("%d", result(100));
    return 0;
}
