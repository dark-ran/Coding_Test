#include<iostream>
#include<queue>

using namespace std;

string arr[101];
bool vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct s {
	int x, y, cnt;
	bool operator<(const s& other) const {
		return cnt > other.cnt; 
	}
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int M, N;
	cin >> M >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	priority_queue<s>pq;
	s cur;
	cur.x = 0;
	cur.y = 0;
	cur.cnt = 0;
	pq.push(cur);
	int res = 1987654321;
	while (!pq.empty()) {
		cur = pq.top();
		pq.pop();
		if (vis[cur.x][cur.y]) continue;
		vis[cur.x][cur.y] = true;
		if (cur.x == N - 1 && cur.y == M - 1) {
			res = res < cur.cnt ? res : cur.cnt;
			continue;
		}
		for (int i = 0;i < 4;i++) {
			int nx = cur.x + dx[i];
			int ny  = cur.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny]) continue;
			int cnt = cur.cnt;
			if (arr[nx][ny] > '0') cnt += 1;
			pq.push({ nx,ny,cnt });
		}
	}
	cout << res;
}