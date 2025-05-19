#include<iostream>

using namespace std;

bool vis[100000001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	const long MOD = 4294967296;
	long n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (!vis[i]) {
			for (int j = i * i; j <= n; j += i) {
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