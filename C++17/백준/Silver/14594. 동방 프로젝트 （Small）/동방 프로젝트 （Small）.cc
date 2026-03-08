#include<iostream>

using namespace std;

int par[101];
bool vis[101];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		par[i] = i;
	}
	while (M--) {
		int x, y;
		cin >> x >> y;
		for (int i = x + 1;i <= y;i++) {
			par[i] = par[i - 1];
		}
	}

	vis[1] = true;
	int cnt = 1;
	for (int i = 2;i <= N;i++) {
		par[i] = par[par[i]];
		if (!vis[par[i]]) {
			cnt++;
			vis[par[i]] = true;
		}
	}

	cout << cnt;
}