#include <stdio.h>

int a, b, c;

long long func() {
    long long d = 1;
    long long base = a % c;
    while (b > 0) {
        if (b & 1) {
            d = d * base % c;
        }
        base = base * base % c;
        b >>= 1;
    }
    return d;
}

int main() {
    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", func());
}
