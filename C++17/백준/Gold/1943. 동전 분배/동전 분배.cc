#include<iostream>
#include<vector>
#define pii pair<int,int>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	for (int T = 0;T < 3;T++) {
		int N, sum = 0;
		cin >> N;
		vector<vector<bool>>dp;
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
		bool check = false;
		dp.resize(N + 1, vector<bool>(sum + 1, false));
		for (int i = 1;i <= data[0].second;i++) {
			if (data[0].first * i > sum) break;
			if (data[0].first * i == sum) {
				check = true;
				break;
			}
			dp[0][data[0].first * i] = true;
		}
		if (check) {
			cout << "1\n";
			continue;
		}

		for (int i = 1;i < N;i++) {
			dp[i - 1][0] = true;
			for (int j = 0;j <= sum;j++) {
				if (dp[i - 1][j]) {
					dp[i][j] = true;
					for (int k = 1;k <= data[i].second;k++) {
						if (j + data[i].first * k > sum)break;
						else if (j + data[i].first * k == sum) {
							check = true;
							break;
						}
						dp[i][j + data[i].first * k] = true;
					}
					if (check)
						break;
				}
			}
			if (check)
				break;
		}
		cout << (check ? "1\n" : "0\n");
	}
}