#include<iostream>

using namespace std;

int cost[101];
int reward[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, T;
	cin >> N >> T;
	for (int i = 0;i < N;i++)
		cin >> cost[i] >> reward[i];

	for (int i = 0;i < N;i++)
		for (int j = T;j >= cost[i];j--)
			dp[j] = (dp[j] > dp[j - cost[i]] + reward[i] ? dp[j] : dp[j - cost[i]] + reward[i]);

	cout << dp[T];
}