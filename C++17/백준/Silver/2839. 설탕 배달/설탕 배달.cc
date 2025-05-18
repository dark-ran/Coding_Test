#include<iostream>
#define min(a,b) a<b?a:b

using namespace std;

int dp[5001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n;
	cin >> n;
	fill(dp, dp + n + 1, 50001);
	for (int i = 1; i <= n/3; i++) {
		dp[i * 3] = i;
	}
	dp[5] = 1;
	for (int i = 1; i <= n / 5; i++) {
		dp[i * 5] = i;
	}
	for (int i = 6; i <= n; i++) {
		dp[i] = min(min(dp[i - 3] + 1, dp[i - 5] + 1), dp[i]);
	}
	if (dp[n] == 50001) {
		cout << -1;
	}
	else
		cout << dp[n];
}