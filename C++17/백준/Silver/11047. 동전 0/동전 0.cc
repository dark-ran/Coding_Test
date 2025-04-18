#include<iostream>
using namespace std;

int dis[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> dis[i];
	for (int i = n - 1; i >= 0; i--) {
		if (dis[i] <= k) {
			cnt += k / dis[i];
			k %= dis[i];
		}
		if (k == 0) break;
	}
	cout << cnt;
}