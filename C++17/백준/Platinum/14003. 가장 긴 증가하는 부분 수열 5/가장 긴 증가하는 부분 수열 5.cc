#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

static const int ISIZE = 1 << 21;
static char ibuf[ISIZE];
static char* in_ptr = ibuf;
static char* end_ptr = ibuf;

inline char get() {
    if (in_ptr == end_ptr) {
        end_ptr = ibuf + fread(ibuf, 1, ISIZE, stdin);
        in_ptr = ibuf;
        if (in_ptr == end_ptr) return EOF;
    }
    return *in_ptr++;
}

void nextLong(ll& x) {
    x = 0;
    char c;
    bool flag = true;
    while ((c = get()) < '-' && c != EOF);
    if (c == EOF) return;
    if (c == '-') {
        flag = false;
        c = get();
    }
    for (; c >= '0'; c = get()) {
        x = (x << 3) + (x << 1) + (c - '0');
    }
    if (!flag) x = -x;
}

const int OSIZE = 1 << 21;
char obuf[OSIZE];
static int oidx = 0;

inline void write(ll x) {
    if (oidx + 20 >= OSIZE) {
        fwrite(obuf, 1, oidx, stdout);
        oidx = 0;
    }
    if (x == 0) {
        obuf[oidx++] = '0';
        obuf[oidx++] = ' ';
        return;
    }
    if (x < 0) {
        obuf[oidx++] = '-';
        x = -x;
    }
    int s = oidx;
    while (x > 0) {
        obuf[oidx++] = x % 10 + '0';
        x /= 10;
    }
    int e = oidx - 1;
    while (s < e) {
        char t = obuf[s];
        obuf[s] = obuf[e];
        obuf[e] = t;
        s++;
        e--;
    }
    obuf[oidx++] = ' ';
}

const int SIZE = 1'000'005;
ll arr[SIZE];
int idx[SIZE];
ll lis[SIZE];

int main() {
    ll N;
    nextLong(N);

    int lis_len = 0;
    for (int i = 0; i < N; i++) {
        nextLong(arr[i]);

        auto it = lower_bound(lis, lis + lis_len, arr[i]);
        if (it == lis + lis_len) {
            lis[lis_len++] = arr[i];
            idx[i] = lis_len;
        } else {
            *it = arr[i];
            idx[i] = it - lis + 1;
        }
    }

    ll cnt = lis_len;
    write(cnt);
    obuf[oidx - 1] = '\n';

    vector<ll> result;
    result.reserve(cnt);
    for (int i = N - 1; i >= 0 && cnt > 0; i--) {
        if (idx[i] == cnt) {
            result.push_back(arr[i]);
            cnt--;
        }
    }

    reverse(result.begin(), result.end());
    for (ll num : result) {
        write(num);
    }
    fwrite(obuf, 1, oidx, stdout);
}