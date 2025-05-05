#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, s, e;
	cin >> N;
	vector<int>arr(N + 1);
	vector<vector<bool>>dp(N + 1, vector<bool>(N + 1, false));
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i][i] = true;
		if (arr[i - 1] == arr[i]) dp[i - 1][i] = true;
	}
	
	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 1; j <= N; j++) {
			if (dp[i + 1][j - 1] && arr[i]==arr[j])
				dp[i][j] = true;
		}
	}

	cin >> M;
	while (M--) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}