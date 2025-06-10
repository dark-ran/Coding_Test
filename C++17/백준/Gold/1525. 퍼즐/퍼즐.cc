#include<iostream>
#include<map>
#include<queue>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

struct Board {
	int data[3][3];
	bool operator<(const Board& other)const{
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				if (data[i][j] != other.data[i][j]) {
					return data[i][j] < other.data[i][j];
				}
			}
		}
		return false;
	}
	bool operator==(const Board& other) const {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (data[i][j] != other.data[i][j])
					return false;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	Board inital;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> inital.data[i][j];
		}
	}
	map<Board, int>ma;
	ma[inital] = 0;
	queue<Board>q;
	q.push(inital);

	Board board = inital;
	board.data[0][0] = 1; board.data[0][1] = 2; board.data[0][2] = 3;
	board.data[1][0] = 4; board.data[1][1] = 5; board.data[1][2] = 6;
	board.data[2][0] = 7; board.data[2][1] = 8; board.data[2][2] = 0;
	if (inital == board) {
		cout << 0;
		return 0;
	}
	while (!q.empty()) {
		Board cur = q.front();
		q.pop();
		int cnt = ma[cur];

		pair<int, int>zero;
		for (int i = 0;i < 3;i++) {
			if (cur.data[i][0] == 0) {
				zero = { i,0 };
				break;
			}
			else if (cur.data[i][1] == 0) {
				zero = { i,1 };
				break;
			}
			else if (cur.data[i][2] == 0) {
				zero = { i,2 };
				break;
			}
		}
		for (int i = 0;i < 4;i++) {
			int nx = zero.first + dx[i];
			int ny = zero.second + dy[i];
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			Board next = cur;
			next.data[zero.first][zero.second] = next.data[nx][ny];
			next.data[nx][ny] = 0;	

			if (ma.find(next) != ma.end()) continue;

			if (next == board) {
				cout << cnt + 1;
				return 0;
			}
			ma[next] = cnt + 1;
			q.push(next);
		}
	}
	cout << "-1";
}