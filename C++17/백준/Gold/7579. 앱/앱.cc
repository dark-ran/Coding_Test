#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1e7 + 1;
int N, M, sum = 0;
int dp[10001];
vector<pair<int, int>>v;

void INPUT() {
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i < N; i++) cin >> v[i].first;
	for (int i = 0; i < N; i++) {
		cin >> v[i].second;
		sum += v[i].second;
	}
}
void SOL() {
	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= v[i].second; j--) {
			dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
		}
	}
	int res = MAX;
	for (int i = 0; i <= sum; i++)
		if (dp[i] >= M)
			res = min(res, i);
	cout << res;
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	INPUT();
	SOL();
}