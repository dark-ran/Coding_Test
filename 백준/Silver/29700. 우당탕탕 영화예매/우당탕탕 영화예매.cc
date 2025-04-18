#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	int res = 0;
	string str;
	while (N--) {
		int a = 0;
		cin >> str;
		for (int i = 0; i < M; i++) {
			if (str[i] == '1') {
				if (a >= K) res += a - K + 1;
				a = 0;
			}
			else a++;
		}
		if (a >= K) res += a - K + 1;
	}
	cout << res;
}