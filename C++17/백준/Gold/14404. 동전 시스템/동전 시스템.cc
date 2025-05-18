#include<iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int A, B, x;
	cin >> A >> B >> x;
	if (A % x == 0 && B % x == 0) {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	for (int i = 1; i <= 200; i++) {
		bool a = false;
		bool b = false;
		for (int j = 0; j * i <= A; j++) {
			if ((A - j * i) % x == 0) {
				a = true;
				break;
			}
		}
		for (int j = 0; j * i <= B; j++) {
			if ((B - j * i) % x == 0) {
				b = true;
				break;
			}
		}
		if (a && b)cnt++;
	}
	cout << cnt;
}