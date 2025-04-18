#include<iostream>
#include<vector>

#define INF 1e9

using namespace std;

int sum[501];
int dp[501][501];
int A[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T, K;
    cin >> T;
    while (T--) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> sum[i];
            sum[i] += sum[i - 1];
            A[i][i] = i;
        }
        for (int i = 1; i < K; i++) {
            for (int j = 1; j <= K - i; j++) {
                dp[j][j + i] = INF;
                for (int k = A[j][j + i - 1]; k <= A[j + 1][j+ i]; k++) {
                    int t = dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1];
                    if (dp[j][j + i] > t) {
                        dp[j][j + i] = t;
                        A[j][j + i] = k;
                    }
                }
            }
        }
        cout << dp[1][K] << "\n";
    }
}