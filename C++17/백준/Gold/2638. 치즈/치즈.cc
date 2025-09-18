#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	int cheese = 0, time = 0;
	vector<vector<int>>arr(N, vector<int>(M));
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if(arr[i][j])
				cheese++;
		}
	
	while (true) {
		if (cheese == 0) {
			cout << time << flush;
			return 0;
		}
		time++;
		vector<vector<int>>vis(N, vector<int>(M, 0));
		queue<pii>q;
		q.push({ 0,0 });
		vis[0][0] = 1;
		while (!q.empty()) {
			pii cur = q.front();
			q.pop();
			for (int i = 0;i < 4;i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (arr[nx][ny] == 0 && !vis[nx][ny]) {
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
				else if (arr[nx][ny] == 1) {
					if (++vis[nx][ny] == 2) {
						arr[nx][ny] = 0;
						cheese--;
					}
				}
			}
		}
	}
}