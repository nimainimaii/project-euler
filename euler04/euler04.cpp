#include <cstdio>
#include <iostream>

bool IsPali(long long number){
    long long rev = 0;
    long long num = number;
    while (num != 0) {
        int digit = num%10;
        num /= 10;
        rev = rev * 10 + digit;
    }
    return rev == number;
}

int main() {
    long long largest_pali = -1;
    for (long long i=111; i<=999; i++) {
        for (long long j=111; j<=999; j++) {
            if(IsPali(i*j) && i*j > largest_pali) {
                largest_pali = i*j;
            }
        }
    }
    printf("%lld", largest_pali);
    //printf("%d", IsPali(100));
    return 0;
}
