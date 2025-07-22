#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int>par(N + 1);
		int x, y;
		for (int i = 1;i < N;i++) {
			cin >> x >> y;
			par[y] = x;
		}
		vector<bool>vis(N + 1);
		cin >> x >> y;
		vis[x] = true;
		while (par[x] != 0) {
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