#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct s{
    int num,x, y, flag;
};
struct cmp {
    bool operator()(s a, s b) {
        return a.num > b.num;
    }
};

bool visited[51][51][3];//{ x , y , 이전 종류(0:모음 1:자음 2:자음+자음) }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N, M, sum = 1000000;
    cin >> N >> M;
    vector<vector<int>>v(N + 1, vector<int>(M + 1));
    priority_queue<s,vector<s>,cmp>q;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> v[i][j];

    if (v[0][0] > 13) {//시작이 모음이면
        cout << "BAD";
        return 0;
    }

    q.push({ 0, 0, 0, false });
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        if (cur.x == N - 1 && cur.y == M - 1) {
            if (cur.flag) { //자음 + 자음으로 끝나지 않는지(cur.flag가 flase면 안됨)
                sum = sum < cur.num ? sum : cur.num; //최소치
            }
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int cx = cur.x + dx[i];
            int cy = cur.y + dy[i];
            if (cx < 0 || cx >= N || cy < 0 || cy >= M) continue;
            bool cflag = v[cx][cy] <= 13 ? true : false; //true : 자음 false : 모음
            if (cflag && v[cur.x][cur.y] <= 13) { //현재가 자음이고 이전도 자음일 때
                if (cur.flag) { //하지만 받침으로 가능할 때
                    if (!visited[cx][cy][2]) {
                        q.push({ cur.num,cx,cy,false });
                        visited[cx][cy][2] = true;
                    }
                }
            }
            else if (cflag) { //현재가 자음이고 이전은 모음일 때
                if (!visited[cx][cy][cflag]) {
                    q.push({ cur.num,cx,cy,true }); //받침으로 가능(true)
                    visited[cx][cy][cflag] = true;
                }
            }
            else if (!cflag) { //현재가 모음이라면
                if (v[cur.x][cur.y] <= 13) { //이전이 자음일 때
                    if (!visited[cx][cy][cflag]) {
                        q.push({ cur.num + 1,cx,cy,true });//횟수+1
                        visited[cx][cy][cflag] = true;
                    }
                }
            }

        }
    }
    if (sum == 1000000) cout << "BAD";
    else cout << sum;
}