#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int x, y;
const int MAX = 1000000;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

struct S {
    int x, y, cnt;
};

int bfs(pair<int, int> start, pair<int, int> end, vector<string>& v) {
    vector<vector<bool>> vis(y, vector<bool>(x, false));
    queue<S> q;
    q.push({ start.first, start.second, 0 });
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (make_pair(cur.x, cur.y) == end) {
            return cur.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= y || ny < 0 || ny >= x) continue;
            if (vis[nx][ny] || v[nx][ny] == 'x') continue;

            vis[nx][ny] = true;
            q.push({ nx, ny, cur.cnt + 1 });
        }
    }
    return -1;
}

int solve(vector<vector<int>>& dp) {
    int n = dp.size();
    vector<vector<int>> memo(n, vector<int>(1 << n, MAX));

    memo[0][1 << 0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;
            if (memo[i][mask] == MAX) continue;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                int new_mask = mask | (1 << j);
                memo[j][new_mask] = min(memo[j][new_mask], memo[i][mask] + dp[i][j]);
            }
        }
    }

    int full_mask = (1 << n) - 1;
    int result = MAX;
    for (int i = 1; i < n; i++) {
        result = min(result, memo[i][full_mask]);
    }

    return (result == MAX) ? -1 : result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;

        vector<string> board(y);
        vector<pair<int, int>> points;
        points.push_back({ 0, 0 });

        for (int i = 0; i < y; i++) {
            cin >> board[i];
            for (int j = 0; j < x; j++) {
                if (board[i][j] == '*') points.push_back({ i, j });
                else if (board[i][j] == 'o') points[0] = { i, j };
            }
        }

        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        bool impossible = false;

        for (int i = 0; i < n && !impossible; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = bfs(points[i], points[j], board);
                dp[j][i] = dp[i][j];
                if (dp[i][j] == -1) {
                    impossible = true;
                    break;
                }
            }
        }

        if (impossible) {
            cout << "-1\n";
            continue;
        }

        cout << solve(dp) << "\n";
    }

}