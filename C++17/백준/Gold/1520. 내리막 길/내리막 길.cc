#include<iostream>
#include<queue>

using namespace std;

int arr[501][501];
int dp[501][501];
bool vis[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct s {
	int x, y;
	int num;
	bool operator<(const s&other)const{
		return num < other.num;
	}
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int M, N;
	cin >> M >> N;
	for (int i = 0;i < M;i++)
		for (int j = 0;j < N;j++)
			cin >> arr[i][j];

	priority_queue<s>pq;
	pq.push({ 0,0,arr[0][0] });
	dp[0][0] = 1;
	while (!pq.empty()) {
		s cur = pq.top();
		pq.pop();
		if (vis[cur.x][cur.y]) continue;
		vis[cur.x][cur.y] = true;
		for (int i = 0;i < 4;i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N || arr[nx][ny] >= arr[cur.x][cur.y]) continue;
			dp[nx][ny] += dp[cur.x][cur.y];
			pq.push({ nx,ny,arr[nx][ny] });
		}
	}
	cout << dp[M - 1][N - 1];
}