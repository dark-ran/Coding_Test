#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& swanCnt, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return;
    parent[b] = a;
    swanCnt[a] += swanCnt[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;
    vector<string> board(R);
    vector<pair<int, int>> swans;

    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'L') swans.push_back({ i,j });
        }
    }

    vector<vector<int>> comp(R, vector<int>(C, -1));
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vector<vector<bool>> inQ(R, vector<bool>(C, false));
    queue<pair<int, int>> melt;

    vector<int> parent;
    vector<int> swanCnt;

    int id = 0;

    // 초기 물 영역 나누기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (vis[i][j] || board[i][j] == 'X') continue;

            queue<pair<int, int>> bfs;
            bfs.push({ i,j });
            vis[i][j] = true;

            parent.push_back(id);
            swanCnt.push_back(0);

            while (!bfs.empty()) {
                auto [x, y] = bfs.front();
                bfs.pop();
                comp[x][y] = id;

                if (board[x][y] == 'L') swanCnt[id]++;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                    if (board[nx][ny] == 'X') {
                        if (!inQ[nx][ny]) {
                            inQ[nx][ny] = true;
                            melt.push({ nx, ny });
                        }
                    }
                    else if (!vis[nx][ny]) {
                        vis[nx][ny] = true;
                        bfs.push({ nx, ny });
                    }
                }
            }
            id++;
        }
    }

    for (int i = 0; i < id; i++) {
        if (swanCnt[find(parent, i)] == 2) {
            cout << 0;
            return 0;
        }
    }

    int day = 0;

    while (!melt.empty()) {
        int sz = melt.size();
        day++;

        while (sz--) {
            auto [x, y] = melt.front();
            melt.pop();

            board[x][y] = '.';

            vector<int> near;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                if (board[nx][ny] != 'X' && comp[nx][ny] != -1) {
                    near.push_back(find(parent, comp[nx][ny]));
                }
            }

            if (near.empty()) continue;

            int root = near[0];
            comp[x][y] = root;

            for (int k = 1; k < (int)near.size(); k++) {
                unite(parent, swanCnt, root, near[k]);
                root = find(parent, root);
            }

            comp[x][y] = root;

            if (swanCnt[find(parent, root)] == 2) {
                cout << day;
                return 0;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                if (board[nx][ny] == 'X' && !inQ[nx][ny]) {
                    inQ[nx][ny] = true;
                    melt.push({ nx, ny });
                }
                else if (board[nx][ny] != 'X' && comp[nx][ny] != -1) {
                    unite(parent, swanCnt, root, comp[nx][ny]);
                    root = find(parent, root);
                }
            }

            if (swanCnt[find(parent, root)] == 2) {
                cout << day;
                return 0;
            }
        }
    }
}