#include<iostream>

using namespace std;

int par[250001], arr[250001];
bool vis[250001];

int find(int x) {
	if (par[x] < 0) return x;
	return par[x] = find(par[x]);
}

void Union(int x, int y) {
	int X = find(x);
	int Y = find(y);
	par[Y] += par[X];
	par[X] = Y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		par[i - 1] = -1;
	}

	long long ans = 0;
	for (int i = N; i >= 1; i--) {
		vis[arr[i]] = true;
		if (arr[i] > 0 && vis[arr[i] - 1]) Union(arr[i] - 1, arr[i]);
		if (arr[i] < N - 1 && vis[arr[i] + 1])Union(arr[i], arr[i] + 1);
		ans += -par[find(arr[i])];
	}
	cout << ans;
}