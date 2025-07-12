#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, cur_id;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

vector<int> cnt;
vector<vector<int>> id;
vector<string> arr;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    id[x][y] = cur_id;
    int count = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != '0' || id[nx][ny] != -1)
                continue;
            id[nx][ny] = cur_id;
            q.push({ nx, ny });
            count++;
        }
    }
    cnt.push_back(count);
    cur_id++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    arr.resize(N);
    id.assign(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '0' && id[i][j] == -1) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '0') {
                cout << '0';
            }
            else {
                int used[4] = { -1, -1, -1, -1 }; 
                int unique_count = 0;
                int sum = 1;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M || id[nx][ny] == -1)
                        continue;

                    bool is_new = true;
                    for (int l = 0; l < unique_count; l++) {
                        if (used[l] == id[nx][ny]) {
                            is_new = false;
                            break;
                        }
                    }
                    if (is_new) {
                        used[unique_count++] = id[nx][ny];
                        sum += cnt[id[nx][ny]];
                    }
                }
                cout << sum % 10;
            }
        }
        cout << '\n';
    }
}