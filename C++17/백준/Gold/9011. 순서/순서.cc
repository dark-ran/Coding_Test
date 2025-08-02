#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 2) {}

    void update(int idx, int delta) {
        for (; idx < tree.size(); idx += idx & -idx)
            tree[idx] += delta;
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += tree[idx];
        return res;
    }

    int findKth(int k) {
        int left = 1, right = tree.size() - 1;
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = query(mid);
            if (val >= k) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> R(n);
        for (int i = 0; i < n; ++i)
            cin >> R[i];

        FenwickTree ft(n);
        for (int i = 1; i <= n; ++i)
            ft.update(i, 1);

        vector<int> S(n);
        bool valid = true;

        for (int i = n - 1; i >= 0; --i) {
            int k = (i + 1) - R[i];
            if (k < 1) {
                valid = false;
                break;
            }
            int pos = ft.findKth(k);
            if (pos == 0) {
                valid = false;
                break;
            }
            S[i] = pos;
            ft.update(pos, -1);
        }

        if (!valid) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int num : S)
                cout << n - num + 1 << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}