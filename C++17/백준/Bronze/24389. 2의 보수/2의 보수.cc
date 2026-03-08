#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b, c, d;
	cin >> a;
	b = ~a + 1;
	c = a ^ b;
	d = 0;
	for (int i = 0; i < 32; i++) {
		if (c&(1<<i)) d++; 
	}
	cout << d;
}
