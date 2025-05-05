#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M, red, blue, risk;
	cin >> N >> M;
	vector<vector<int>>dp(51, vector<int>(51, -1));
	dp[0][0] = 0;
	for (int i = 0; i < M; i++) {
		cin >> red >> blue >> risk;
		for (int r = 50; r >=red; r--) {
			for (int b= 50;  b>=blue; b--) {
				if (dp[r - red][b - blue] == -1) continue;
				dp[r][b] = max(dp[r][b], dp[r - red][b - blue] + risk);
			}
		}
	}

	vector<pair<int, int>>people(N);
	for (int i = 0; i < N; i++) {
		cin >> red >> blue;
		if (dp[red][blue] == -1) people[i] = { 0,i + 1 };
		else people[i] = { dp[red][blue],i + 1 };
	}
	sort(people.begin(), people.end());
	for (auto a : people) cout << a.second << " " << a.first << "\n";
}