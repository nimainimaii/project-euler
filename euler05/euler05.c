#include <stdio.h>

int gcd(int a, int b) {
    while (b % a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }

    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int result = 1;
    for (int i = 2; i < 20; i++) {
        result = lcm(result, i);
    }
    printf("%d", result);
    return 0;
}
