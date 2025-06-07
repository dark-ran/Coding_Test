#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int k = N - i - j;
			if (j > k) break;
			if (k < i + j) cnt++;
		}
	}
	cout << cnt;
}