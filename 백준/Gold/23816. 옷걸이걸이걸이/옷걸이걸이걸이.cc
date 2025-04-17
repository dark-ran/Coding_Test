#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>>tree{ //{옷걸이, 옷}
		{1,1},
		{3,2},
		{7,4},
		{15,0}
	};
	vector<int>dp(M + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		vector<int>dp2(M + 1, -1);
		for (auto& a : tree) {
			for (int j = a.first; j <= M; j++) {
				if (dp[j - a.first] == -1) continue;
				dp2[j] = max(dp2[j], dp[j - a.first] + a.second);
			}
		}

		swap(dp, dp2);
		dp[M] = max(dp[M], dp2[M]);
	}
	cout << dp[M];
}
