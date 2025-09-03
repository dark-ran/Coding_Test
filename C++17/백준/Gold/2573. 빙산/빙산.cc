#include<iostream>
#include<queue>
#include<vector>
#define pii pair<int,int>
using namespace std;

vector<vector<int>> arr;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int bfs(int x, int y) {
    queue<pii> q;
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    q.push({ x,y });
    vis[x][y] = true;
    int cnt = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] || arr[nx][ny] <= 0) continue;
            q.push({ nx,ny });
            vis[nx][ny] = true;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    arr.resize(N, vector<int>(M));
    queue<pii> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0)
                q.push({ i,j });
        }

    int year = 0;
    while (true) {
        int total_icebergs = q.size();
        if (total_icebergs == 0) {
            cout << 0;
            return 0;
        }
        if (bfs(q.front().first, q.front().second) != total_icebergs) {
            cout << year;
            return 0;
        }

        vector<vector<int>> next = arr;
        int a = q.size();
        while (a--) {
            pii cur = q.front();
            q.pop();
            int sea_count = 0;
            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (arr[nx][ny] <= 0) sea_count++;
            }
            next[cur.first][cur.second] = arr[cur.first][cur.second] - sea_count;
            if (next[cur.first][cur.second] > 0) {
                q.push(cur);
            }
        }
        arr = next;
        year++;
    }
}