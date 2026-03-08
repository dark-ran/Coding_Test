#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[100000];
bool check[100000]{ false };
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	int y;
	for (int i = 0; i < arr[x].size(); i++) {
		y = arr[x][i];
		while (!check[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}