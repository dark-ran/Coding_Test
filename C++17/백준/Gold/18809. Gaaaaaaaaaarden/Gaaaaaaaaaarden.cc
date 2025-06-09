#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, G, R, ans = 0;
vector<pair<int, int>> pos;
int arr[50][50];
int times[50][50];
char color[50][50];

void bfs(const vector<pair<int, int>>& greens, const vector<pair<int, int>>& reds) {
    for (int i = 0; i < N; i++) {
        fill(times[i], times[i] + M, -1);
        fill(color[i], color[i] + M, ' ');
    }

    queue<pair<int, int>> q;
    static const int dx[4] = { 1, 0, -1, 0 };
    static const int dy[4] = { 0, 1, 0, -1 };

    // 초기화
    for (const auto& p : greens) {
        times[p.first][p.second] = 0;
        color[p.first][p.second] = 'G';
        q.push(p);
    }
    for (const auto& p : reds) {
        times[p.first][p.second] = 0;
        color[p.first][p.second] = 'R';
        q.push(p);
    }

    int flowers = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        if (times[x][y] == -2) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 0) continue;

            if (times[nx][ny] == -1) {
                times[nx][ny] = times[x][y] + 1;
                color[nx][ny] = color[x][y];
                q.push({ nx, ny });
            }
            else if (times[nx][ny] == times[x][y] + 1 && color[nx][ny] != color[x][y]) {
                flowers++;
                times[nx][ny] = -2; // 꽃으로 표시
            }
        }
    }

    if (ans < flowers) ans = flowers;
}

void select(int idx, int g_remain, int r_remain, vector<pair<int, int>>& greens, vector<pair<int, int>>& reds) {
    if (g_remain == 0 && r_remain == 0) {
        bfs(greens, reds);
        return;
    }
    if (idx >= pos.size()) return;

    if (pos.size() - idx < g_remain + r_remain) return;

    select(idx + 1, g_remain, r_remain, greens, reds);

    if (g_remain > 0) {
        greens.push_back(pos[idx]);
        select(idx + 1, g_remain - 1, r_remain, greens, reds);
        greens.pop_back();
    }

    if (r_remain > 0) {
        reds.push_back(pos[idx]);
        select(idx + 1, g_remain, r_remain - 1, greens, reds);
        reds.pop_back();
    }
}

int main() {
    scanf("%d %d %d %d", &N, &M, &G, &R);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 2) {
                pos.push_back({ i, j });
            }
        }
    }

    vector<pair<int, int>> greens, reds;
    greens.reserve(G);
    reds.reserve(R);

    select(0, G, R, greens, reds);
    printf("%d\n", ans);
}