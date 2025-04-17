#include<iostream>
#include<vector>

using namespace std;

int hp[21];
int joy[21];
vector<int>dp(100, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, res = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hp[i];
	}
	for (int i = 0; i < N; i++) cin >> joy[i];
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 99; j >= hp[i]; j--) {
			if (dp[j - hp[i]] != -1) {
				dp[j] = max(dp[j - hp[i]] + joy[i], dp[j]);
				res = max(res, dp[j]);
			}
		}
	}
	cout << res;
}