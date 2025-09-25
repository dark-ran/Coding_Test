#include<iostream>
#include<cstring>
using namespace std;

int pre[25], cur[25];
const int w[25] = {
    1,2,2,2,2,2,1,3,4,3,2,3,1,3,4,2,4,3,1,3,2,3,4,3,1
};

inline int idx(int i, int j) { return i * 5 + j; }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a; cin >> a;
    if (!a) { cout << 0; return 0; }

    memset(pre, 0, sizeof(pre));
    pre[idx(a, 0)] = pre[idx(0, a)] = 2;

    while (cin >> a && a) {
        memset(cur, 0, sizeof(cur));

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int p = pre[idx(i, j)];
                if (!p) continue;

                int c1 = p + w[idx(i, a)];
                int c2 = p + w[idx(j, a)];
                int& r1 = cur[idx(a, j)];
                int& r2 = cur[idx(i, a)];

                if (!r1 || c1 < r1) r1 = c1;
                if (!r2 || c2 < r2) r2 = c2;
            }
        }
        memcpy(pre, cur, sizeof(pre));
    }

    int res = 123456789;
    for (int i = 0; i < 25; i++)
        if (pre[i] && pre[i] < res) res = pre[i];

    cout << res;
    return 0;
}