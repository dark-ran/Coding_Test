#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N;
	vector<int>arr(N + 1);
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> M;

	vector<vector<int>>dp(4, vector<int>(N + 1));
	for (int i = 1;i <= 3;i++) {
		for (int j = i * M;j <= N;j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - M] + arr[j] - arr[j - M]);
		}
	}
	cout << dp[3][N];
}