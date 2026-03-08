#include<iostream>
#include<queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dis[102][102]{ 0 };//거리 넣는 곳
string board[102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	//bfs시작
	queue < pair<int, int>>q;
	q.push({ 0,0 });
	dis[0][0] = 1;
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (dis[nx][ny] > 0 || board[nx][ny] != '1') continue;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	cout << dis[n - 1][m - 1];
}