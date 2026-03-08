#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>arr;
vector<int>vis;
int idx = 1;

void bfs(int x) {
	vis[x] = idx++;
	for (int a : arr[x]) {
		if (!vis[a]) {
			bfs(a);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M, R;
	cin >> N >> M >> R;
	arr.resize(N);
	for (int i = 0;i < M;i++) {
		int u, v;
		cin >> u >> v;
		arr[u - 1].push_back(v - 1);
		arr[v - 1].push_back(u - 1);
	}
	for (int i = 0;i < N;i++)
		sort(arr[i].begin(), arr[i].end());

	vis.resize(N, 0);
	bfs(R - 1);
	for (int i = 0;i < N;i++)
		cout << vis[i] << "\n";
}