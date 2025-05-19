#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	const long MOD = 4294967296;
	long n;
	cin >> n;
	vector<bool>vis(n + 1);
	for (int i = 4; i <= n; i += 2)
		vis[i] = true;
	int sqrt_n = sqrt(n);
	for (int i = 3; i <= sqrt_n; i += 2) {
		if (!vis[i]) {
			for (int j = i * i; j <= n; j += 2 * i) {
				vis[j] = true;
			}
		}
	}
	long cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			long j = i;
			while (j * i <= n) {
				j *= i;
			}
			cnt = (cnt * j) % MOD;
			if (cnt < 0)cnt += MOD;
		}
	}
	if (cnt < 0)cnt += MOD;
	cout << cnt;
}