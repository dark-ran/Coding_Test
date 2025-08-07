#include<iostream>
#include<vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<string>arr;
bool vis[26];
int R, C, MAX = 0;

void dfs(int x, int y, int cnt) {
	MAX = MAX > cnt ? MAX : cnt;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C || vis[arr[nx][ny] - 'A']) continue;
		vis[arr[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		vis[arr[nx][ny] - 'A'] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> R >> C;
	arr.resize(R);
	for (int i = 0;i < R;i++)
		cin >> arr[i];
	vis[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << MAX << flush;
}