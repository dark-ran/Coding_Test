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
			if (cur_x < 0 || cur_x == n || cur_y < 0 || cur_y == n) continue; //범위밖
			int idx = 0;
			if (maze[cur_x][cur_y] == '0') idx++; //벽이면
			if (arr[cur.first][cur.second] + idx < arr[cur_x][cur_y]) arr[cur_x][cur_y] = arr[cur.first][cur.second] + idx; //계산값이 원래값보다 작으면
			else continue; //아니라면 이미 계산 되었으므로 뺵!
			q.push({ cur_x, cur_y });
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		cin >> maze[i];
	}
	for (int i = 0;i < n;i++) {
		fill(arr[i], arr[i] + n, 2600);
	}
	arr[0][0] = 0;
	dfs(0, 0);
	printf("%d", arr[n - 1][n - 1]);
}