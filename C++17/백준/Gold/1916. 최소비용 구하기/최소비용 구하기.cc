#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int checked[1001]; //도시까지 가는데 비용
int arr[1001][1001]; //저장된 비용값들

int main() {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		checked[i] = -1;
	}

	vector<vector<int>>v(n + 1); //도로 있는 것
	while (m--) { 
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x][y] == -1) {
			arr[x][y] = z;
			v[x].push_back(y);
		}
		else {
			arr[x][y] = arr[x][y] < z ? arr[x][y] : z;
		}
	}
	int x, y;
	cin >> x >> y;
	checked[x] = 0;

	queue<pair<int,int>>q;
	for (auto i : v[x]) q.push({ x, i });

	while (!q.empty()) {
		x = q.front().first; //시작
		int p = q.front().second;//도착
		q.pop();
		if (checked[p] == -1) {
			checked[p] = checked[x] + arr[x][p];
			for (auto i : v[p]) q.push({ p,i });
		}
		else {
			if (checked[p] > checked[x] + arr[x][p]) {
				checked[p] = checked[x] + arr[x][p];
				for (auto i : v[p]) q.push({ p,i });
			}
		}
	}
	cout << checked[y];
}