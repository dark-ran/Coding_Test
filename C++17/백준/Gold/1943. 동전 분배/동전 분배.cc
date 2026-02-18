#include<iostream>
#include<vector>
#define pii pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	for (int T = 0;T < 3;T++) {
		int N, sum = 0;
		cin >> N;
		vector<pii>data(N);
		for (int i = 0;i < N;i++) {
			cin >> data[i].first >> data[i].second;
			sum += (data[i].first * data[i].second);
		}
		if (sum & 1) {
			cout << "0\n";
			continue;
		}
		sum >>= 1;
		vector<int>items;
		for (int i = 0;i < N;i++) { //binary splitting
			int value = data[i].first;
			int count = data[i].second;
			for (int k = 1;count > 0;k <<= 1) {
				int use = min(k, count);
				items.push_back(value * use);
				count -= use;
			}
		}

		vector<bool>dp(sum + 1, false);
		dp[0] = true;
		for (int w : items) { // 0/1 knapsack
			for (int j = sum;j >= w;j--) {
				if (dp[j - w])
					dp[j] = true;
			}
		}
		cout << (dp[sum] ? "1\n" : "0\n");
	}
}