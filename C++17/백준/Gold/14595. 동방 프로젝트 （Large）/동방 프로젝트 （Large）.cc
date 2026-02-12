#include <iostream>
using namespace std;

int parent[1000001];
int nxt[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        nxt[i] = i + 1;
    }

    int cnt = N;

    while (M--) {
        int x, y;
        cin >> x >> y;

        int cur = x;
        while (cur < y) {
            cur = find(cur);     // 이미 처리된 구간 점프
            if (cur >= y) break;

            unite(cur, cur + 1);
            cnt--;

            parent[cur] = cur + 1; // 경로 압축용
        }
    }

    cout << cnt;
}
