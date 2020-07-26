#include <stdio.h>

int main() {
  // general form of pythagorean triplets is a = m2 - n2, b = 2mn, c = m2 + n2
  // a + b + c = 2m(m+n) = 1000
  for (int m = 0; m < 1000; m++) {
    for (int n = 0; n < 1000; n++) {
      if (m * (m + n) == 500) {
        long long int answer = m * m - n * n;
        answer *= 2 * m * n;
        answer *= m * m + n * n;
        printf("%lld\n", answer);
      }
    }
  }
  return 0;
}
