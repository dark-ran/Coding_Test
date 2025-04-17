#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>arr;
vector<vector<int>>dp; //{위치, 횟수}
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K;
	cin >> N >> M >> K;
	arr.resize(N + 1, vector<int>(N + 1, -1));
	dp.resize(N + 1, vector<int>(M + 1, -1));
	int x, y, z;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> z;
		if (x > y) continue;
		arr[x][y] = max(arr[x][y], z);
	}
	dp[1][1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (arr[i][j] == -1) continue;
			for (int k = 1; k < M; k++) {
				if (dp[i][k] == -1) continue;
				dp[j][k + 1] = max(dp[j][k + 1], dp[i][k] + arr[i][j]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= M; i++) res = max(res, dp[N][i]);
	cout << res;
}