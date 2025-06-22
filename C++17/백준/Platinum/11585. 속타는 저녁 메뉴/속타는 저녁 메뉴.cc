#include<stdio.h>

using namespace std;

const int MAX = 1'000'001;
char p[MAX];
int N;

static const int ISIZE = 1 << 21;
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
void next_int(int& a) {
    a = 0;
    char c;
    while ((c = get()) < '0');
    do {
        a = (a << 3) + (a << 1) + c - '0';
    } while ((c = get()) >= '0');
}

bool check(int i) {
    for (int j = i; j < N; j += i) {
        for (int k = 0; k < i; k++) {
            if (p[k] != p[k + j]) return false;
        }
    }
    return true;
}

int main() {
    next_int(N);
    for (int i = 0; i < N; i++)
        next_char(p[i]);

    int M = (N >> 1) + 1;
    for (int i = 1; i < M; i++) {
        if (N % i) continue;
        if (check(i)) {
            printf("1/%d", i);
            return 0;
        }
    }
    printf("1/%d", N);
}