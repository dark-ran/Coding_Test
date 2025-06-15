#include <iostream>
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
    if (!flag)x = -x;
}

const int SIZE = 1'000'005;
ll arr[SIZE];
vector<ll> lis;
int idx[SIZE];

int main() {
    ll N;
    nextLong(N);

    for (int i = 0; i < N; i++) {
        nextLong(arr[i]);

        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it == lis.end()) {
            lis.push_back(arr[i]);
            idx[i] = lis.size();
        }
        else {
            *it = arr[i];
            idx[i] = it - lis.begin() + 1;
        }
    }

    ll cnt = lis.size();
    cout << cnt << "\n";

    vector<ll> result;
    for (int i = N - 1; i >= 0 && cnt > 0; i--) {
        if (idx[i] == cnt) {
            result.push_back(arr[i]);
            cnt--;
        }
    }

    reverse(result.begin(), result.end());
    for (ll num : result) {
        cout << num << " ";
    }
}