#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool S[26];
vector<string>v;
int res = 0;
int R, C;

void dfs(int x,int y,int cnt) {
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C || S[v[nx][ny] - 'A']) continue;
		S[v[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		S[v[nx][ny] - 'A'] = false;
	}
	res = (res > cnt ? res : cnt);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> R >> C;
	v.resize(R);
	for (int i = 0;i < R;i++)
		cin >> v[i];
	S[v[0][0] - 'A'] = true;
	dfs(0,0,1);
	cout << res;
}