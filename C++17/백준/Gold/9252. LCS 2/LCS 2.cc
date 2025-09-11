#include<iostream>
#include<vector>

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			dp[i][j] = (a[i] == b[j] ? 1 : 0);
		}
	}
	for (int i = 1;i < n;i++) {
		if (dp[i - 1][0]) {
			dp[i][0] = 1;
		}
	}

	for (int j = 1;j < m;j++) {
		if (dp[0][j - 1]) {
			dp[0][j] = 1;
		}
	}

	for (int i = 1;i < n;i++) {
		for (int j = 1;j < m;j++) {
			if (dp[i][j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	vector<char>res(dp[n - 1][m - 1]);
	int idx = dp[n - 1][m - 1] - 1;
	if (dp[n - 1][m - 1] > 0) {
		string lcs;
		int i = n - 1, j = m - 1;

		while (i >= 0 && j >= 0) {
			if (a[i] == b[j]) {
				res[idx--] = a[i];
				i--;
				j--;
			}
			else {
				if (i > 0 && j > 0) {
					if (dp[i - 1][j] > dp[i][j - 1]) {
						i--;
					}
					else {
						j--;
					}
				}
				else if (i > 0) {
					i--;
				}
				else {
					j--;
				}
			}
		}
	}

	cout << dp[n - 1][m - 1] << "\n";
	for (int i = 0;i < dp[n - 1][m - 1];i++)
		cout << res[i];
}