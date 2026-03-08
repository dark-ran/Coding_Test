#include<iostream>
#include<queue>
using namespace std;

int board[502][502]{ 0 };
bool vis[502][502]{ false };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, max = 0, size;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j])
				continue;
			queue < pair<int, int>>q;
			q.push({ i,j });
			size = 0;
			vis[i][j] = true;
			while (!q.empty()) {
				pair<int, int>cur = q.front();
				q.pop();
				size++;
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					vis[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			max = max > size ? max : size;
			cnt++;
		}
	}
	cout << cnt << "\n" << max;
}