#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[1003][1003];
int m, n, num = 0, max_ = 1;

queue<pair<int, int>>q;

void bfs() {
	int nx[4] = { 1,0,-1,0 };
	int ny[4] = { 0,-1,0,1 };
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ix = x + nx[k];
			int iy = y + ny[k];
			if (ix > n || ix < 1 || iy > m || iy < 1) continue;

			if (arr[ix][iy] == 0) { //안익었다면
				arr[ix][iy] = arr[x][y] + 1;
				q.push({ ix,iy });
				num--;
			}

			else if (arr[ix][iy] > 1) {//이미 값이 있다면
				if (arr[ix][iy] > arr[x][y] + 1) {
					arr[ix][iy] = arr[x][y] + 1;
					q.push({ ix,iy });
				}
			}

			max_ = max(max_, arr[ix][iy]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	for (int i = 1; i <= n; i++) { //Input
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) num++;
			else if(arr[i][j]==1) q.push({ i,j });
		}
	}

	bfs();

	if (num != 0) { //Check
		cout << "-1";
		return 0;
	}

	cout << max_ - 1;
}