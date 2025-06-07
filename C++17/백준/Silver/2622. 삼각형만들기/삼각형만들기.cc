#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int max_l = (N % 2 == 0 ? N / 2 - 1 : N / 2);
	int cnt = 0;
	for (int i = 1; i <= max_l; i++) {
		for (int j = i; j <= max_l; j++) {
			int k = N - i - j;
			if (k > max_l || i > k || j > k) continue;
			cnt++;
		}
	}
	cout << cnt;
}