#include<iostream>
#include<vector>
#include<queue>
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
using namespace std;

int N, L, R;
int arr[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool bfs(int x, int y, vector<vector<bool>>& vis, vector<pii>& union_cells) {
    queue<pii> q;
    q.push({ x, y });
    vis[x][y] = true;
    int sum = arr[x][y];
    union_cells.push_back({ x, y });

    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue;
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
        for (pii& cell : union_cells) arr[cell.first][cell.second] = avg;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int res = 0;
    vector<pii> next_starts;
    for (int i = 0;i < N;i++)
        for (int j = (i % 2 == 0 ? 0 : 1);j < N;j++)
            next_starts.push_back({ i,j });

    while (true) {
        vector<vector<bool>> vis(N, vector<bool>(N, false));
        bool moved = false;
        vector<pii> current_starts;

        for (pii a : next_starts) {
            if (vis[a.first][a.second]) continue;
            vector<pii> union_cells;
            if (bfs(a.first, a.second, vis, union_cells)) {
                moved = true;
                for (pii& cell : union_cells) 
                    current_starts.push_back(cell);
            }
        }

        if (!moved) {
            cout << res;
            return 0;
        }
        res++;
        next_starts = current_starts;
    }
}