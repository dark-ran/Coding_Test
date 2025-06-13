#include<iostream>
#define ll long long

using namespace std;

ll dp[100'002];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, T, K;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			int S, E;
			cin >> S >> E;
			dp[S + 1]++;
			dp[E + 1]--;
		}
	}

	for (int i = 1; i < 100'001; ++i) {
		dp[i] += dp[i - 1];
	}
	for (int i = 1; i < 100'001; ++i) {
		dp[i] += dp[i - 1];
	}

	ll MAX = -1;
	int s = 0, e = 0;
	for (int i = T; i < 100'001; ++i) {
		if (MAX < dp[i] - dp[i - T]) {
			MAX = dp[i] - dp[i - T];
			s = i - T;
			e = i;
		}
	}
	cout << s << " " << e;
}