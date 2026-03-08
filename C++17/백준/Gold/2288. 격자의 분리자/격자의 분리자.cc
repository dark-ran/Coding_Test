#include <iostream>
#include <queue>
#include <tuple>
#include<cstring>

using namespace std;

const int MAX_N = 201;
const int MAX_M = 201;

int dir[3][2] = { {0, -1}, {1, 0}, {0, 1} }; // 왼쪽, 아래, 오른쪽
int N, M;
char board[MAX_N][MAX_M];
bool isVisited[MAX_N][MAX_M];
int res;

void execBFS(queue<tuple<int, int, int>>& que) {
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int step = get<2>(cur);

        if (x == N - 1) {
            res = step;
            return;
        }

        for (int i = 0; i < 3; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != 'S') continue;
            if (isVisited[nx][ny]) continue;

            que.push(make_tuple(nx, ny, step + 1));
            isVisited[nx][ny] = true;
        }
    }
}

void solution() {
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            for (int j = 0; j < M; j++) {
                board[i][j] = input[j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                if (board[i][j] == 'S') {
                    if ((j == 0 || j == N - 1)) {
                        if (j < M - 2) {
                            board[i][j + 1] = 'S';
                            break;
                        }
                    }
                    else {
                        if (j < M - 1) {
                            board[i][j + 1] = 'S';
                            break;
                        }
                    }
                }
            }
        }

        queue<tuple<int, int, int>> que;
        memset(isVisited, false, sizeof(isVisited));
        for (int i = 1; i < M - 1; i++) {
            if (board[0][i] == 'S') {
                que.push(make_tuple(0, i, 1));
                isVisited[0][i] = true;
            }
        }

        res = -1;
        execBFS(que);

        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}