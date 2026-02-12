#include <iostream>

using namespace std;

int par[1000001];

int find(int a) {
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    par[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        par[i] = i;

    int cnt = N;

    while (M--) {
        int x, y;
        cin >> x >> y;

        for (int i = find(x); i < y; i = find(i + 1)) {
            int next = find(i + 1);
            if (i != next) {
                par[i] = next;
                cnt--;
            }
        }
    }

    cout << cnt;
}
