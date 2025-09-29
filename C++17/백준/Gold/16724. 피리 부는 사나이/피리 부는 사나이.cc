#include<iostream>
#include<vector>
#define pii pair<int,int>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt = 0;
vector<vector<int>>arr, vis;

void func(int x, int y) {
	vis[x][y] = 1;
	int idx = arr[x][y];
	int nx = x + dx[idx];
	int ny = y + dy[idx];
	if (vis[nx][ny] == 0) func(nx, ny);
	else if (vis[nx][ny] == 1) cnt++;
	vis[x][y] = 2;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, M;
	string s;
	cin >> N >> M;
	arr.resize(N,vector<int>(M));
	vis.resize(N, vector<int>(M));
	for (int i = 0;i < N;i++) {
		cin >> s;
		for (int j = 0;j < M;j++) {
			switch (s[j]) {
			case 'U':
				arr[i][j] = 0;
				break;
			case'D':
				arr[i][j] = 1;
				break;
			case'L':
				arr[i][j] = 2;
				break;
			case'R':
				arr[i][j] = 3;
				break;
			}
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (vis[i][j] != 0) continue;
			func(i, j);
		}
	}
	cout << cnt << flush;
}