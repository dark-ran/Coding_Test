#include<iostream>
#include<unordered_map>
#include<queue>
#include<tuple>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

struct Board {
    int data[3][3];
    int zero_x, zero_y; // 0의 위치를 저장

    bool operator==(const Board& other) const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (data[i][j] != other.data[i][j])
                    return false;
        return true;
    }

    size_t hash() const {
        size_t h = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                h = h * 10 + data[i][j];
        return h;
    }
};

namespace std {
    template<> struct hash<Board> {
        size_t operator()(const Board& b) const {
            return b.hash();
        }
    };
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    Board initial;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> initial.data[i][j];
            if (initial.data[i][j] == 0) {
                initial.zero_x = i;
                initial.zero_y = j;
            }
        }
    }

    // 목표 상태 정의
    Board target;
    target.data[0][0] = 1; target.data[0][1] = 2; target.data[0][2] = 3;
    target.data[1][0] = 4; target.data[1][1] = 5; target.data[1][2] = 6;
    target.data[2][0] = 7; target.data[2][1] = 8; target.data[2][2] = 0;
    if (initial == target) {
        cout << 0;
        return 0;
    }

    unordered_map<Board, int> visited;
    queue<Board> q;

    visited[initial] = 0;
    q.push(initial);

    while (!q.empty()) {
        Board cur = q.front();
        q.pop();
        int cnt = visited[cur];

        for (int i = 0; i < 4; i++) {
            int nx = cur.zero_x + dx[i];
            int ny = cur.zero_y + dy[i];

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

            Board next = cur;
            swap(next.data[cur.zero_x][cur.zero_y], next.data[nx][ny]);
            next.zero_x = nx;
            next.zero_y = ny;

            if (visited.find(next) != visited.end()) continue;

            if (next == target) {
                cout << cnt + 1;
                return 0;
            }

            visited[next] = cnt + 1;
            q.push(next);
        }
    }

    cout << "-1";
}