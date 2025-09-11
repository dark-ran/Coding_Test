#include<iostream>

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	string a, b;
	cin >> a >> b;
	for (int i = 0;i < a.size();i++) {
		for (int j = 0;j < b.size();j++) {
			dp[i][j] = (a[i] == b[j] ? 1 : 0);
		}
	}
	for (int i = 1;i < a.size();i++) {
		if (dp[i - 1][0]) {
			dp[i][0] = 1;
		}
	}

	for (int j = 1;j < b.size();j++) {
		if (dp[0][j - 1]) {
			dp[0][j] = 1;
		}
	}

	for (int i = 1;i < a.size();i++) {
		for (int j = 1;j < b.size();j++) {
			if (dp[i][j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	cout << dp[a.size() - 1][b.size() - 1];
}