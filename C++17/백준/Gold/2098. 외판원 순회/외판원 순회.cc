#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1 << 16;
const int INF = 1e9;
int cost[16][16];
int dp[16][MAX];
int N;
int des;

int dfs(int idx, int vis) {
	if (vis == des) return cost[idx][0] == 0 ? INF : cost[idx][0];
	if (dp[idx][vis] != -1) return dp[idx][vis];

	dp[idx][vis] = 1987654321;
	for (int i = 0; i < N; i++) {
		if ((vis & (1 << i)) == 0 && cost[idx][i] != 0) {
			dp[idx][vis] = min(dp[idx][vis], dfs(i, vis | (1 << i)) + cost[idx][i]);
		}
	}
	return dp[idx][vis];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];
	des = (1 << N) - 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= des; j++)
			dp[i][j] = -1;

	cout << dfs(0, 1);
}