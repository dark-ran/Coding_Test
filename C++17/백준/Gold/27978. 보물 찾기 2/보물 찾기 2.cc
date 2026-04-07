#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct s {
	int res, x, y;
};
struct cmp {
	bool operator()(const s& a, const s& b) {
		return (a.res > b.res);
	}
};

int zero_nx[3] = { 1,-1,0 };
int zero_ny[3] = { 1,1,1 };
int plus_nx[5] = { 1,1,0,-1,-1 };
int plus_ny[5] = { 0,-1,-1,-1,0 };

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int H, W, st_x, st_y;
	cin >> H >> W;
	vector<string>v(H);
	for (int i = 0;i < H;i++) {
		cin >> v[i];
		for (int j = 0;j < W;j++) {
			if (v[i][j] == 'K') {
				st_x = i;
				st_y = j;
			}
		}
	}

	priority_queue<s, vector<s>, cmp>pq;
	pq.push({ 0,st_x,st_y });
	vector<vector<bool>>vis(H, vector<bool>(W,false));

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (v[cur.x][cur.y] == '*') { //find treasure
			cout << cur.res;
			return 0;
		}
		if (vis[cur.x][cur.y]) continue;
		vis[cur.x][cur.y] = true;
		for (int i = 0;i < 5;i++) {
			int dx = plus_nx[i] + cur.x;
			int dy = plus_ny[i] + cur.y;
			if (dx < 0 || dy < 0 || dx >= H || dy >= W || vis[dx][dy] || v[dx][dy] == '#') continue;
			pq.push({ cur.res + 1,dx,dy });
		}
		for (int i = 0;i < 3;i++) {
			int dx = zero_nx[i] + cur.x;
			int dy = zero_ny[i] + cur.y;
			if (dx < 0 || dy < 0 || dx >= H || dy >= W || vis[dx][dy] || v[dx][dy] == '#') continue;
			pq.push({ cur.res,dx,dy });
		}
	}
	cout << -1;
}