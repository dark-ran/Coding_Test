#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, K, i, a, b;
	cin >> N >> M >> K;
	int tot = N * 4;

	vector<int>left(K);
	for (i = 1; i <= tot % K; i++) {
		left[i] = tot / K + 1;
	}
	for (; i < K; i++) {
		left[i] = tot / K;
	}
	left[0] = tot / K;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		left[a % K]--;
		left[b % K]--;
	}

	cin >> a >> b;
	left[a % K]--;
	left[b % K]--;
	int diff = abs(a % K - b % K);
	int l = 0, r = 1 + diff;
	int sum = 0;
	int val = 0;
	for (int i = diff + 1; i < K; i++) {
		val += left[i - diff - 1];
		sum += min(val, left[i]);
		val -= min(val, left[i]);
	}
	cout << (sum < M - 1 ? sum : M - 1);
}