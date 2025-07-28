#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int>arr(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b;
		if (a <= 2)
			cin >> c;
		if (a == 1)
			arr[b] |= (1 << c);
		else if (a == 2)
			arr[b] &= ~(1 << c);
		else if (a == 3) {
			arr[b] = arr[b] << 1;
			arr[b] &= ((1 << 21) - 1);
		}
		else if (a == 4) {
			arr[b] = arr[b] >> 1;
			arr[b] &= ~1;
		}
	}
	vector<bool>vis(1 << 21);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[arr[i]] == false)
			res++;
		vis[arr[i]] = true;
	}
	cout << res;
}