#include<iostream>
#include<vector>

using namespace std;

int par[10'001];
bool vis[10'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 1;i <= N;i++) {
			par[i] = i;
			vis[i] = false;
		}
		int x, y;
		for (int i = 1;i < N;i++) {
			cin >> x >> y;
			par[y] = x;
		}
		cin >> x >> y;
		vis[x] = true;
		while (par[x] != x) {
			x = par[x];
			vis[x] = true;
		}

		while (true) {
			if (vis[y]) {
				cout << y << "\n";
				break;
			}
			y = par[y];
		}
	}
}