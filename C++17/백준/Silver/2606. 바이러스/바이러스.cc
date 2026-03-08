#include<iostream>
#include<vector>
using namespace std;

vector<int>arr[101];
bool check[101]{ false };
int cnt = 0;
void dfs(int x) {
	check[x] = true;
	int y;
	for (int i = 0; i < arr[x].size(); i++) {
		y = arr[x][i];
		if (!check[y]) {
			dfs(y);
			cnt++;
		}
	}
}

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;//컴퓨터의 수,컴퓨터 쌍의 수
	int u, v;
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	dfs(1);
	cout << cnt;
}
