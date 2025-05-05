#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1e5 + 1;
int dp[MAX];
int weight[101];
int cost[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> cost[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = K; j >= weight[i]; j--)
            dp[j] = max(dp[j], dp[j - weight[i]] + cost[i]);

    cout << dp[K];
}