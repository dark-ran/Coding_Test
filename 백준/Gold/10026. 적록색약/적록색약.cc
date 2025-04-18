#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	queue<pair<int,int>>q;
	vector<string>v(N);
	vector<vector<bool>>visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
		cin >> v[i];

	char flag;
	pair<int, int>res = { 0,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			q.push({ i,j });
			flag = v[i][j];
			res.first++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int x = cur.first + dx[k];
					int y = cur.second + dy[k];
					if (x >= 0 && x < N && y >= 0 && y < N && v[x][y] == flag && !visited[x][y]) {
						visited[x][y] = true;
						q.push({ x,y });
					}
				}
			}
		}
	}
	visited.assign(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			q.push({ i,j });
			flag = v[i][j];
			res.second++;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int x = cur.first + dx[k];
					int y = cur.second + dy[k];
					if (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]) {
						if ((flag == 'R' && v[x][y] == 'G') || (flag == 'G' && v[x][y] == 'R') || flag == v[x][y]) {
							visited[x][y] = true;
							q.push({ x,y });
						}
					}
				}
			}
		}
	}
	cout << res.first << " " << res.second;
}
