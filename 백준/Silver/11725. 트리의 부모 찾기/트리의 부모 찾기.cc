#include<iostream>
#include<vector>

using namespace std;

int n;
int arr[100001];
bool visited[100001];
vector<int>v[100001];

void dfs(int k) {
	visited[k] = true;
	for (int i = 0; i < v[k].size(); i++) {
		int t = v[k][i];
		if (!visited[t]) {
			arr[t] = k;
			dfs(t);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n;
	for (int i = 1; i < n;i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << arr[i] << "\n";
	}
}