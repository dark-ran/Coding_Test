#include<iostream>
#include<queue>
#include<set>
#include<vector>
#define pii pair<int,int>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct s {
	int cnt;
	pii red;
	pii blue;
};

string board[10];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	s cur;
	cur.cnt = 0;
	for (int i = 0;i < N;i++) {
		cin >> board[i];
		for (int j = 0;j < M;j++) {
			if (board[i][j] == 'B') {
				cur.blue = { i,j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R') {
				cur.red = { i,j };
				board[i][j] = '.';
			}
		}
	}

	set<pair<pii, pii>>se;
	se.insert({ cur.red,cur.blue });
	queue<s>q;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		if (cur.cnt >= 10) {
			cout << -1 << flush;
			return 0;
		}
		for (int i = 0;i < 4;i++) {
			cur = q.front();
			bool flag = true;
			bool succeed = false;
			while (true) { //blue
				int nx = cur.blue.first + dx[i];
				int ny = cur.blue.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#')
					break;
				if (board[nx][ny] == 'O') {
					flag = false;
					break;
				}
				if (cur.red.first == nx && cur.red.second == ny) {
					break;
				}
				cur.blue.first = nx;
				cur.blue.second = ny;
			}
			if (!flag) continue; //when blue go in
			while (true) { //red
				int nx = cur.red.first + dx[i];
				int ny = cur.red.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#')
					break;
				if (board[nx][ny] == 'O') {
					succeed = true;
					cur.red.first = nx;
					cur.red.second = ny;
					break;
				}
				if (cur.blue.first == nx && cur.blue.second == ny) {
					break;
				}
				cur.red.first = nx;
				cur.red.second = ny;
			}
			while (true) { //blue
				int nx = cur.blue.first + dx[i];
				int ny = cur.blue.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#')
					break;
				if (board[nx][ny] == 'O') {
					flag = false;
					break;
				}
				if (cur.red.first == nx && cur.red.second == ny) {
					break;
				}
				cur.blue.first = nx;
				cur.blue.second = ny;
			}
			if (!flag) continue; //blue and red go in same time
			while (true) { //red
				int nx = cur.red.first + dx[i];
				int ny = cur.red.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#')
					break;
				if (board[nx][ny] == 'O') {
					succeed = true;
					cur.red.first = nx;
					cur.red.second = ny;
					break;
				}
				if (cur.blue.first == nx && cur.blue.second == ny) {
					break;
				}
				cur.red.first = nx;
				cur.red.second = ny;
			}

			if (succeed) {
				cout << cur.cnt + 1 << flush;
				return 0;
			}
			if (se.find({ cur.red, cur.blue }) == se.end()) {
				se.insert({ cur.red,cur.blue });
				cur.cnt++;
				q.push(cur);
				cur.cnt--;
			}
		}
		q.pop();
	}
	cout << -1 << flush;
}