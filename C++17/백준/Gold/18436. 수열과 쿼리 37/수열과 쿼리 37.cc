#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M;
    cin >> N;
    int h = (int)ceil(log2(N));
    int size = 1 << h;
    vector<int> tree_0(size << 1), tree_1(size << 1);

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x & 1) tree_1[size + i] = 1;
        else tree_0[size + i] = 1;
    }

    for (int i = size - 1; i > 0; --i) {
        tree_0[i] = tree_0[i << 1] + tree_0[(i << 1) | 1];
        tree_1[i] = tree_1[i << 1] + tree_1[(i << 1) | 1];
    }

    cin >> M;
    while (M--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            int idx = size + l - 1;
            if (tree_0[idx] && (r & 1)) {
                tree_0[idx] = 0;
                tree_1[idx] = 1;
            }
            else if (tree_1[idx] && !(r & 1)) {
                tree_1[idx] = 0;
                tree_0[idx] = 1;
            }
            else continue;

            for (idx >>= 1; idx; idx >>= 1) {
                tree_0[idx] = tree_0[idx << 1] + tree_0[(idx << 1) | 1];
                tree_1[idx] = tree_1[idx << 1] + tree_1[(idx << 1) | 1];
            }
        }
        else {
            l += size - 1;
            r += size - 1;
            int res = 0;
            while (l <= r) {
                if (l & 1) res += (q == 2 ? tree_0[l] : tree_1[l]);
                if (!(r & 1)) res += (q == 2 ? tree_0[r] : tree_1[r]);
                l = (l + 1) >> 1;
                r = (r - 1) >> 1;
            }
            cout << res << '\n';
        }
    }
}