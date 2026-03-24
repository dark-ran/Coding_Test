#include<iostream>
#include<vector>
#define max(x,y) (x>y?x:y)

using namespace std;

vector<int>par, candy, cnt, dp;

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) { //x에게 맡기기
		candy[x] += candy[y];
		candy[y] = 0;
		cnt[x] += cnt[y];
		cnt[y] = 0;
		par[y] = par[x];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, K, x, y;
	cin >> N >> M >> K;
	candy.resize(N + 1);
	par.resize(N + 1);
	cnt.resize(N + 1);
	dp.resize(K + 1);
	for (int i = 1;i <= N;i++)
		cin >> candy[i];
	for (int i = 1;i <= N;i++) {
		par[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0;i < M;i++) {
		cin >> x >> y;
		_union(x, y);
	}

	for (int i = 1;i <= N;i++) {
		if (candy[i]) { //집합의 최상위가 아니라면
			for (int j = K - 1;j >= cnt[i];j--) {
				dp[j] = max(dp[j], dp[j - cnt[i]] + candy[i]);
			}
		}
	}
	cout << dp[K - 1];
}