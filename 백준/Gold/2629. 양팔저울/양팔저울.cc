#include<iostream>
#include<vector>

using namespace std;

int wei[31];
vector<vector<bool>>dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, T, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wei[i];
		sum += wei[i];
	}
	dp.resize(N + 1, vector<bool>(sum + 1, false));
	for (int i = 1; i <= N; i++) {
		dp[i - 1][0] = true;
		for (int j = 1; j <= sum; j++) {
			if (j >= wei[i - 1] && dp[i - 1][j - wei[i - 1]])
				dp[i][j] = true; //합으로 구하기
			if (dp[i - 1][j]) {
				dp[i][abs(j - wei[i - 1])] = true;
				dp[i][j] = true;
			}
		}
	}
	int x;
	cin >> T;
	while (T--) {
		cin >> x;
		if (x > sum) cout << "N ";
		else if (dp[N][x])cout << "Y ";
		else cout << "N ";
	}
}