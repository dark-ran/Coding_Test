#include<iostream>
#include<vector>

using namespace std;

vector<bool>dp;
vector<int>v;

bool func(int num, int cnt) {
	if (cnt == 1) return dp[num];
	for (int i : v) {
		if (i > num)
			continue;
		if (func(num - i, cnt - 1))
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	dp.resize(N + 1);
	int num = 5;
	for (int i = 1; i <= N;) {
		v.push_back(i);
		dp[i] = true;
		i += num;
		num += 4;
	}
	for (int i = 1; i <= 6; i++) {
		if (func(N, i)) {
			cout << i;
			return 0;
		}
	}
}