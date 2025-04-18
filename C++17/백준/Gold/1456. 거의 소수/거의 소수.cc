#include<iostream>
using namespace std;

bool prime[10000003]{ false };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a, b, c;
	cin >> a >> b;
	int range = b < 10000001 ? b : 10000001;
	int cnt = 0;
	for (long long i = 2; i <= range; i++) {
		if (!prime[i]) {
			c = i;
			while (c <= b / i) {
				if (a <= c * i)
					cnt++;
				c *= i;
			}
			for (int j = i * 2; j <= range; j += i) {
				prime[j] = true;
			}
		}
	}
	cout << cnt;
}