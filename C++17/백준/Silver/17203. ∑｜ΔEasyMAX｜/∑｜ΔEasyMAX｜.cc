#include<iostream>

using namespace std;

int a[1000];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, Q, x, y;
	cin >> N >> Q;
	cin >> x;
	for (int i = 0; i < N - 1; i++) {
		cin >> y;
		a[i] = x < y ? y - x : x - y;
		x = y;
	}
	while(Q--) {
		int sum = 0;
		cin >> x >> y;
		for (; x < y; x++) {
			sum += a[x - 1];
		}
		cout << sum << "\n";
	}
}