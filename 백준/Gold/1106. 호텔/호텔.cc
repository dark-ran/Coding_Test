#include<iostream>

using namespace std;

int cost[21];
int cust[21];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int C, N;
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i] >> cust[i];
		dp[cost[i]] = cust[i];
	}
	int res = 100001;
	for (int i = 0; i < N; i++) {
		for (int j = cost[i];; j++) {
			dp[j] = max(dp[j],dp[j - cost[i]] + cust[i]);
			if (dp[j] >= C) {
				res = min(res, j);
				break;
			}
		}
	}
	cout << res;
}