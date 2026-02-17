#include <iostream>
#include<vector>

using namespace std;

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int diff) {
        while (i <= n) {
            tree[i] += diff;
            i += i & -i;
        }
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += tree[i];
            i -= i & -i;
        }
        return s;
    }

    int range(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    while (cin >> N >> K) {

        Fenwick zero(N);   // 0 개수
        Fenwick neg(N);    // 음수 개수

        vector<int> arr(N + 1);

        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                arr[i] = 0;
                zero.update(i, 1);
            }
            else if (x < 0) {
                arr[i] = -1;
                neg.update(i, 1);
            }
            else {
                arr[i] = 1;
            }
        }

        while (K--) {
            char c;
            int a, b;
            cin >> c >> a >> b;

            if (c == 'C') {
                int newVal;
                if (b == 0) newVal = 0;
                else if (b < 0) newVal = -1;
                else newVal = 1;

                if (arr[a] == newVal) continue;

                // 기존 값 제거
                if (arr[a] == 0) zero.update(a, -1);
                if (arr[a] == -1) neg.update(a, -1);

                // 새 값 추가
                if (newVal == 0) zero.update(a, 1);
                if (newVal == -1) neg.update(a, 1);

                arr[a] = newVal;
            }
            else {
                if (zero.range(a, b) > 0) {
                    cout << "0";
                }
                else {
                    int negCnt = neg.range(a, b);
                    if (negCnt % 2) cout << "-";
                    else cout << "+";
                }
            }
        }
        cout << "\n";
    }
}
