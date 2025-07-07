#include<iostream>

using namespace std;

int dp[100'001][5];
int coins[4] = { 1,5,10,25 };
int cnt[4];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int X;
	cin >> X >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];


	for (int i = 0;i < 4;i++) {
		if (cnt[i]) {
			dp[coins[i]][i]++;
			dp[coins[i]][4]++;
		}
	}
	for (int i = 1;i <= X;i++) {
		for (int j = 0;j < 4;j++) {
			if (i - coins[j] < 0) continue; //음수가 된다면
			if (dp[i - coins[j]][4] == 0) continue; //이전 값이 없다면
			if (dp[i - coins[j]][j] >= cnt[j]) continue; //동전을 이미 다썼다면
			if (dp[i - coins[j]][4] + 1 <= dp[i][4]) continue; //+1하는게 이미 있는 값보다 작거나 같다면

			for (int k = 0;k < 5;k++)
				dp[i][k] = dp[i - coins[j]][k];
			dp[i][j]++;
			dp[i][4]++;
		}
	}

	for (int i = 0;i < 4;i++) {
		cout << dp[X][i] << " ";
	}
}