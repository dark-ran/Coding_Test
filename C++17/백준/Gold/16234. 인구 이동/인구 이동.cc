#include<iostream>
#include<vector>
#include<queue>
#define abs(x) ((x)<0?-(x):(x))
#define pii pair<int,int>
using namespace std;

int N, L, R;
int arr[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool bfs(int x,int y,vector<vector<bool>>*vis) {
	(*vis)[x][y] = true;
	int sum = 0;
	vector<pii>v;
	v.push_back({ x,y });
	int idx = 0;
	while (idx < v.size()) {
		pii cur = v[idx++];
		int num = arr[cur.first][cur.second];
		for (int i = 0;i < 4;i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || (*vis)[nx][ny]) continue;
			if (L <= abs(num - arr[nx][ny]) && abs(num - arr[nx][ny]) <= R) {
				sum += arr[nx][ny];
				(*vis)[nx][ny] = true;
				v.push_back({ nx,ny });
			}
		}
	}
	if (sum > 0) {
		sum += arr[x][y];
		sum /= idx;
		for (pii a : v)
			arr[a.first][a.second] = sum;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> N >> L >> R;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> arr[i][j];

	int res = 0;
	while (true) {
		vector<vector<bool>>vis(N, vector<bool>(N, false));
		bool check = false;
		for (int i = 0;i < N;i++) {
			for (int j = (i % 2 == 0 ? 0 : 1);j < N;j+=2) {
				if (vis[i][j]) continue;
				if (bfs(i, j, &vis))
					check = true;
			}
		}
		if (!check) {
			cout << res;
			return 0;
		}
		else {
			res++;
		}
	}
}