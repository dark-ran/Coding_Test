#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long long n, cnt = 0;
	cin >> n;
	while (n > 0) {
		cnt++;
		n -= cnt;
	}

	if (n < 0) {
		cnt--;
	}
	cout << cnt;
}