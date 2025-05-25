#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T, N, K, target;
	cin >> T;
	int arr[1001];
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		vector<vector<int>>v(N);
		vector<int>degree(N);
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			v[x - 1].push_back(y - 1);
			degree[y - 1]++;
		}

		cin >> target;
		target--;
		vector<int>dp(N);
		queue<int>q;
		for (int i = 0; i < N; i++) {
			if (degree[i] == 0) {
				q.push(i);
				dp[i] = arr[i];
			}
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i : v[cur]) {
				dp[i] = dp[i] > dp[cur] + arr[i] ? dp[i] : dp[cur] + arr[i];
				if (--degree[i] == 0) {
					q.push(i);
				}
			}
		}
		cout << dp[target] << "\n";
	}
}