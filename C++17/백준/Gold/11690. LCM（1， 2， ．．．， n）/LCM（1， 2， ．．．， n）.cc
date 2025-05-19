#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	const long MOD = 4294967296;
	long n;
	scanf("%ld", &n);
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
	long j = 2;
	while (j * 2 <= n) {
		j <<= 1;
	}
	cnt = cnt * j;
	for (int i = 3; i <= n; i+=2) {
		if (!vis[i]) {
			j = i;
			while (j * i <= n) {
				j *= i;
			}
			cnt = (cnt * j) % MOD;
		}
	}
	printf("%ld", cnt);
}