#include <stdio.h>
#include <math.h>

long long LargestPrimeFactor(long long n) {
    long long max_prime = -1;

    while (n%2 == 0) {
        max_prime = 2;
        n = n/2;
    }

    for (long long i=3; i <= sqrt(n); i=i+2) {
        while (n%i == 0) {
            max_prime = i;
            n = n/i;
        }
    }

    if (n>2) max_prime = n;

    return max_prime;
}

int main () {
    long long n = 600851475143;
    printf("%lld", LargestPrimeFactor(n));
    return 0;
}
