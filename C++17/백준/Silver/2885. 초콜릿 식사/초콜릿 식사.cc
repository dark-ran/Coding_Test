#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int K;
	cin >> K;
	int h = (int)ceil(log(K) / log(2));
	int a = 1 << h;
	int b = 0;
	for (int i = 0;i < h;i++) {
		if (K & (1 << i)) {
			b = h - i;
			break;
		}
	}
	cout << a << " " << b;
}