#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, G, R, ans = 0;
vector<pair<int, int>> pos;
vector<vector<int>> arr;

void bfs(vector<pair<int, int>> greens, vector<pair<int, int>> reds) {
    vector<vector<int>> time(N, vector<int>(M, -1));
    vector<vector<char>> color(N, vector<char>(M, ' '));
    queue<pair<int, int>> q;

    for (auto p : greens) {
        time[p.first][p.second] = 0;
        color[p.first][p.second] = 'G';
        q.push(p);
    }
    for (auto p : reds) {
        time[p.first][p.second] = 0;
        color[p.first][p.second] = 'R';
        q.push(p);
    }

    int flowers = 0;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        if (time[x][y] == -2) continue; // already a flower

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0) continue;

            if (time[nx][ny] == -1) {
                time[nx][ny] = time[x][y] + 1;
                color[nx][ny] = color[x][y];
                q.push({ nx, ny });
            }
            else if (time[nx][ny] == time[x][y] + 1 && color[nx][ny] != color[x][y]) {
                flowers++;
                time[nx][ny] = -2; // mark as flower
            }
        }
    }
    ans = max(ans, flowers);
}

void select(int idx, int g, int r, vector<pair<int, int>>& greens, vector<pair<int, int>>& reds) {
    if (g == 0 && r == 0) {
        bfs(greens, reds);
        return;
    }
    if (idx >= pos.size()) return;

    // Not select current position
    select(idx + 1, g, r, greens, reds);

    // Select as green if possible
    if (g > 0) {
        greens.push_back(pos[idx]);
        select(idx + 1, g - 1, r, greens, reds);
        greens.pop_back();
    }

    // Select as red if possible
    if (r > 0) {
        reds.push_back(pos[idx]);
        select(idx + 1, g, r - 1, greens, reds);
        reds.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M >> G >> R;
    arr.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                pos.push_back({ i, j });
            }
        }
    }

    vector<pair<int, int>> greens, reds;
    select(0, G, R, greens, reds);
    cout << ans << '\n';
}