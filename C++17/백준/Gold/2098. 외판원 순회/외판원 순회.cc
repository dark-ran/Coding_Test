#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1 << 25;
int cost[16][16];
int dp[66000][16];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
			if (!cost[i][j]) cost[i][j] = MAX;
		}
	int des = (1 << N - 1) - 1;

	for (int i = 0; i <= des; i++) {
		for (int j = 0; j < N - 1; j++) {
			dp[i][j] = MAX;
			if (i == (1 << j)) dp[i][j] = cost[N-1][j];
			else if (i & (1 << j)) {
				for (int k = 0; k < N - 1; k++) {
					if (k == j) continue;
					int p = i ^ (1 << j);
					dp[i][j] = min(dp[i][j], dp[p][k] + cost[k][j]);
				}
			}
		}
	}
	int res = MAX;
	for (int i = 0; i < N - 1; i++) {
		res = min(res, dp[des][i] + cost[i][N - 1]);
	}
	cout << res;
}