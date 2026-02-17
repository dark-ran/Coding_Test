#include <iostream>
#include <algorithm>

using namespace std;

int ma[1002][1002];
int dp[1002][1002];
int left_dp[1002];
int right_dp[1002];

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> ma[i][j];


    dp[1][1] = ma[1][1];
    for (int j = 2; j <= M; j++)
        dp[1][j] = dp[1][j - 1] + ma[1][j];

    for (int i = 2; i <= N; i++) {

        // left to right
        left_dp[1] = dp[i - 1][1] + ma[i][1];
        for (int j = 2; j <= M; j++) {
            left_dp[j] = max(left_dp[j - 1], dp[i - 1][j]) + ma[i][j];
        }
        //right to left
        right_dp[M] = dp[i - 1][M] + ma[i][M];
        for (int j = M - 1; j >= 1; j--) {
            right_dp[j] = max(right_dp[j + 1], dp[i - 1][j]) + ma[i][j];
        }

        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(left_dp[j], right_dp[j]);
        }
    }

    cout << dp[N][M];
}
