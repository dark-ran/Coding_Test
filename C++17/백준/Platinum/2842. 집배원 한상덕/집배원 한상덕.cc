#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

string arr[51];
int height[51][51];
pair<int, int>start;
int N;
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { 1,0,-1,-1,-1,0,1,1 };

bool bfs(int left, int right,int des) {
	queue<pair<int, int>>q;
	vector<vector<bool>>vis(N, vector<bool>(N, false));
	if (left > height[start.first][start.second] || right < height[start.first][start.second])
		return false;
	q.push(start);
	vis[start.first][start.second] = true;
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (arr[cur.first][cur.second] == 'K') {
			cnt++;
		}
		for (int i = 0; i < 8; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny<0 || ny >= N  || left > height[nx][ny] || right < height[nx][ny] || vis[nx][ny])
				continue;
			vis[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
	return (cnt == des);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'P')
				start = { i,j };
			else if (arr[i][j] == 'K')
				cnt++;
		}
	}

	vector<int>heights;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			heights.push_back(height[i][j]);
		}
	sort(heights.begin(), heights.end());
	heights.erase(unique(heights.begin(), heights.end()), heights.end());
	int ans = 1e9;
	int m = heights.size();
	int s = 0, e = 0;
	while (e < m) { //control e
		while (s<=e) {//control s
			if (!bfs(heights[s], heights[e], cnt)) {
				break;
			}
			ans = ans < heights[e] - heights[s] ? ans : heights[e] - heights[s];
			s++;
		}
		e++;
	}
	cout << ans << flush;
}