#include <stdio.h>

long long sumEvenFibBruteForce(long long n) {
    long long a = 1, b = 1;
    long long sum = 0;

    while (a <= n) {
        if (a % 2 == 0) {
            sum += a;
        }

        long long next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

long long sumEvenFibOptimized(long long n) {
    long long e1 = 2;
    long long e2 = 8;
    long long sum = 0;

    while (e1 <= n) {
        sum += e1;

        long long next = 4 * e2 + e1;
        e1 = e2;
        e2 = next;
    }

    return sum;
}

int main() {
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", sumEvenFibBruteForce(n));

    printf("%lld\n", sumEvenFibOptimized(n));

    return 0;
}