#include <iostream>
#include<queue>

using namespace std;

int n, m, x, y;
int cnt = 0;
int check[102];
int arr[102][102];
queue<int>q;

void bfs(int k) {
    q.push(k);
    while (!q.empty()) {
        k = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (arr[k][i] != 0 && !check[i]) {
                q.push(i);
                check[i] = check[k] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> n >> x >> y >> m;
    while (m--) {
        cin >> a >> b;
        arr[a][b] = 1;;
        arr[b][a] = 1;
    }
    bfs(x);
    if (!check[y])
        cout << "-1";
    else
        cout << check[y];
}