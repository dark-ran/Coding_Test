#include<iostream>

using namespace std;

int coins[20];
int dp[10'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		for (int i = 0;i < N;i++)
			cin >> coins[i];
		cin >> M;
		for (int i = 0;i <= M;i++)
			dp[i] = 0;

		dp[0] = 1;
		for (int i = 0;i < N;i++) {
			int x = coins[i];
			for (int j = x;j <= M;j++)
				dp[j] += dp[j - x];
		}
		cout << dp[M] << "\n";
	}
}