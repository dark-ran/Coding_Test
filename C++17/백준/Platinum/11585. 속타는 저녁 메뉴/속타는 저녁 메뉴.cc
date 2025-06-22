#include<stdio.h>

using namespace std;

const int MAX = 1'000'001;
char s[MAX * 2];
char p[MAX];
int f[MAX];

static const int ISIZE = 1 << 22;
static char ibuf[ISIZE];
static char* in_ptr;
static char* end_ptr;
inline char get() {
    if (in_ptr == end_ptr) {
        end_ptr = ibuf + fread(ibuf, 1, ISIZE, stdin);
        in_ptr = ibuf;
    }
    return *in_ptr++;
}
void next_char(char&c) {
    while ((c = get()) < 'A');
}
void next_int(int&a) {
    a = 0;
    char c;
    while ((c = get()) < '0');
    do {
        a = (a << 3) + (a << 1) + c - '0';
    } while ((c = get()) >= '0');
}

inline int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int N;
    next_int(N);
    for (int i = 0; i < N; i++)
        next_char(s[i]);
    for (int i = 0; i < N; i++)
        next_char(p[i]);

    for (int i = 0; i < N; i++)
        s[N + i] = s[i];

    f[0] = 0;
    for (int i = 1, j = 0; i < N; i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        j += (p[i] == p[j]);
        f[i] = j;
    }

    int C = 0;
    for (int i = 0, j = 0; i < 2 * N - 1; i++) {
        while (j > 0 && s[i] != p[j]) j = f[j - 1];
        j += (s[i] == p[j]);
        if (j == N) {
            C++;
            j = f[j - 1];
        }
    }

    int g = gcd(C, N);
    printf("%d/%d", C / g, N / g);
}