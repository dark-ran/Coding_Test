#include<iostream>

using namespace std;

bool dp[1'000'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T, N;
	cin >> T;
	for (int i = 1;i <= 1'000;i++)
		dp[i * i] = true;

	for (int i = 1;i <= 1'000'000;i++) {
		if (!dp[i]) {
			for (int j = 1;j * j + i <= 1'000'000;j++)
				dp[i + j * j] = true;
		}
	}

	while (T--) {
		cin >> N;
		cout << (dp[N] ? "koosaga\n" : "cubelover\n");
	}
}