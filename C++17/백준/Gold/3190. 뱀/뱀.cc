#include<iostream>
#include<deque>

using namespace std;

int dist[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K, x, y, L;
	cin >> N >> K;
	for (int i = 0;i < K;i++) {
		cin >> x >> y;
		dist[x][y] = 1; //사과
	}

	cin >> L;
	int time = 1;
	int dir = 1;
	deque<pair<int, int>>dq;
	dq.push_back({ 1,1 });
	dist[1][1] = 2; //뱀 시작 지점

	for (int i = 0;i < L;i++) {
		char c;
		cin >> x >> c;
		while(time <= x) {
			time++;
			int nx = dq.back().first + dy[dir];
			int ny = dq.back().second + dx[dir];

			if (nx <= 0 || nx > N || ny <= 0 || ny > N || dist[nx][ny] == 2) { //벽 + 몸통 충돌
				cout << time - 1;
				return 0;
			}
			if (dist[nx][ny] != 1) { //사과가 없다면
				dist[dq.front().first][dq.front().second] = 0;
				dq.pop_front();
			}
			dq.push_back({ nx,ny });
			dist[nx][ny] = 2;
		}
		if (c == 'D')
			dir = (dir + 1) % 4;
		else if (c == 'L')
			dir = (dir + 3) % 4;
	}
	for (;;) {
		time++;
		int nx = dq.back().first + dy[dir];
		int ny = dq.back().second + dx[dir];
		if (nx <= 0 || nx > N || ny <= 0 || ny > N || dist[nx][ny] == 2) { //벽 + 몸통 충돌
			cout << time - 1;
			return 0;
		}
		if (dist[nx][ny] != 1) { //사과가 없다면
			dist[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}
		dq.push_back({ nx,ny });
		dist[nx][ny] = 2;
	}
}