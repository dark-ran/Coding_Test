#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2 == 0) {
		a ^= b;
		a ^= b;
	}
	else {
			a ^= b;
	}
	cout << a;
}