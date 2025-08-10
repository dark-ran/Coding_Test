#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#define abs(x) ((x)<0?-(x):(x))
using namespace std;

int N, L, R;
int arr[52][52];
bool vis[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
vector<pair<int, int>> union_cells;

inline int fastRead() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

bool bfs(int x, int y) {
    q.push({ x, y });
    vis[x][y] = true;
    int sum = arr[x][y];
    union_cells.clear();
    union_cells.push_back({ x, y });

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (arr[nx][ny] == -1 || vis[nx][ny]) continue;
            int diff = abs(arr[cur.first][cur.second] - arr[nx][ny]);
            if (L <= diff && diff <= R) {
                vis[nx][ny] = true;
                sum += arr[nx][ny];
                q.push({ nx, ny });
                union_cells.push_back({ nx, ny });
            }
        }
    }

    if (union_cells.size() > 1) {
        int avg = sum / union_cells.size();
        for (auto& cell : union_cells) arr[cell.first][cell.second] = avg;
        return true;
    }
    return false;
}

int main() {
    N = fastRead(); L = fastRead(); R = fastRead();
    memset(arr, -1, sizeof(arr));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            arr[i][j] = fastRead();

    int res = 0;
    vector<pair<int, int>> next_starts;
    for (int i = 1; i <= N; i++)
        for (int j = (i % 2 ? 1 : 2); j <= N; j += 2)
            next_starts.push_back({ i, j });

    while (true) {
        memset(vis, 0, sizeof(vis));
        bool moved = false;
        vector<pair<int, int>> current_starts;

        for (auto& a : next_starts) {
            if (vis[a.first][a.second]) continue;
            if (bfs(a.first, a.second)) {
                moved = true;
                for (auto& cell : union_cells)
                    current_starts.push_back(cell);
            }
        }

        if (!moved) {
            printf("%d", res);
            return 0;
        }
        res++;
        next_starts = move(current_starts);
    }
}