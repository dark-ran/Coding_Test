#include<iostream>

using namespace std;

int arr[3][1001];
int dp[3][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	int res = 1000001;
	for (int first = 0; first < 3; first++) {
		for (int j = 0; j < 3; j++) {
			if (j == first) dp[j][0] = arr[j][0];
			else dp[j][0] = 1000001;
		}
		for (int j = 1; j < N; j++) {
			dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + arr[0][j];
			dp[1][j] = min(dp[2][j - 1], dp[0][j - 1]) + arr[1][j];
			dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + arr[2][j];
		}
		for (int last = 0; last < 3; last++) {
			if (last == first) continue;
			res = min(res, dp[last][N - 1]);
		}
	}
	cout << res;

}