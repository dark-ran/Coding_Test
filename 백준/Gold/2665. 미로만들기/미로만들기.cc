#include<iostream>
#include<queue>

using namespace std;

string maze[51];
int arr[51][51];
int n;

void dfs(int x, int y) {
	int dx[4]{ 1,0,-1,0 };
	int dy[4]{ 0,-1,0,1 };
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		pair<int, int>cur = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			int cur_x = cur.first + dx[i];
			int cur_y = cur.second + dy[i];
			if (cur_x < 0 || cur_x == n || cur_y < 0 || cur_y == n) continue;
			int idx = 0;
			if (maze[cur_x][cur_y] == '0') idx++;
			if (arr[cur.first][cur.second] + idx < arr[cur_x][cur_y]) arr[cur_x][cur_y] = arr[cur.first][cur.second] + idx;
			else continue;
			q.push({ cur_x, cur_y });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	string s;
	for (int i = 0;i < n;i++) {
		cin >> maze[i];
	}
	for (int i = 0;i < n;i++) {
		fill(arr[i], arr[i] + n, 2600);
	}
	arr[0][0] = 0;
	dfs(0, 0);
	cout << arr[n - 1][n - 1]<<"\n";
}