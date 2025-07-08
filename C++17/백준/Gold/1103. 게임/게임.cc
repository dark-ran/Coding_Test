#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int map[50][50];
int visited[50][50];
int dp[50][50];
int min_n = -1;

int dfs(int y, int x) {
	if (x < 0 || x >= n || y < 0 || y >= m || map[y][x] == -1)return 0;
	if (visited[y][x] == 1) {
		cout << -1;
		exit(0);
	}
	if (dp[y][x])return dp[y][x];
	visited[y][x] = 1;
	int dis = map[y][x];
	int dx[4] = { 0,0,dis,-dis };
	int dy[4] = { dis,-dis,0,0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> m >> n;
	for (int y = 0; y < m; y++) {
		string s; cin >> s;
		for (int x = 0; x < n; x++) {
			if (s[x] == 'H') map[y][x] = -1;
			else map[y][x] = s[x] - '0';
		}
	}
	cout << dfs(0, 0); ;
}
