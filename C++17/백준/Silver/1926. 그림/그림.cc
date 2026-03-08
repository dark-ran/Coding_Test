#include<iostream>
using namespace std;

int board[502][502];
bool vis[502][502]{ false };

int dx[4] = { 1,0,-1,0 };//현재값에서 주변 x위치
int dy[4] = { 0,1,0,-1 };//현재값에서 주변 y위치

int cnt = 0;
int siz = 0;
void bfs(int x, int y) {
	vis[x][y] = true;
	siz++;
	for (int i = 0; i < 4; i++) {
		if (board[x+dx[i]][y+dy[i]] == 1 && !vis[x+dx[i]][y+dy[i]]) {//주변 값들 체크중
			bfs(x + dx[i], y + dy[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, max=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				bfs(i, j);
				cnt++;
				max = max > siz ? max : siz;
				siz = 0;
			}
		}
	}
	cout << cnt << "\n" << max;
}