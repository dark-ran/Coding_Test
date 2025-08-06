#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

vector<vector<int>>arr;
vector<vector<bool>>vis;
pii shark;
pii food;
int N;

int bfs(int size) {
	queue<pii>q;
	vis.assign(N, vector<bool>(N, false));
	vis[shark.first][shark.second] = true;
	q.push(shark);
	int dist = 0;
	
	vector<pii> candidates;
	while (!q.empty()) {
		dist++;
		int num = q.size();

		while (num--) {
			pii cur = q.front();
			q.pop();

			for (int i = 0;i < 4;i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny]) continue;

				if (arr[nx][ny] > size)
					continue;

				vis[nx][ny] = true;

				if (arr[nx][ny] != 0 && arr[nx][ny] < size) {
					candidates.push_back({ nx, ny });
				}
				q.push({ nx, ny });
			}
		}

		if (!candidates.empty()) {
			sort(candidates.begin(), candidates.end());
			food = candidates[0];
			return dist;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	cin >> N;

	arr.resize(N, vector<int>(N));
	int feed = 0;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark = { i,j };
				arr[i][j] = 0;
			}
			else if (arr[i][j])
				feed++;
		}
	}
	if (!feed) {
		cout << 0 << flush;
		return 0;
	}
	
	int cnt = 0, size = 2, time = 0;
	while (true) {
		int dist = bfs(size);
		
		if (dist == -1) {
			cout << time << flush;
			return 0;
		}

		arr[food.first][food.second] = 0;
		shark = food;
		if (++cnt == size) {
			size++;
			cnt = 0;
		}

		time += dist;

		if (!(--feed)) {
			cout << time;
			return 0;
		}
	}
}