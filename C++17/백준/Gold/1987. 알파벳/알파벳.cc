#include <iostream>
#include <vector>

using namespace std;

int R, C, MAX = 0;
vector<string> arr;

inline void dfs(int x, int y, int visited, int cnt) {
    static const int dx[] = { 1, 0, -1, 0 };
    static const int dy[] = { 0, 1, 0, -1 };

    MAX = MAX > cnt ? MAX : cnt;
    if (MAX == 26) return;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

        int bit = 1 << (arr[nx][ny] - 'A');
        if (visited & bit) continue;

        dfs(nx, ny, visited | bit, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> R >> C;
    arr.resize(R);
    for (int i = 0; i < R; i++)
        cin >> arr[i];

    dfs(0, 0, 1 << (arr[0][0] - 'A'), 1);
    cout << MAX;
}