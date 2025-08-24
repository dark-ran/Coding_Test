#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;

pii dp[41]; //0, 1
bool vis[41];

void fibo(int n) {
    if (vis[n]) {
        return;
    }
    else {
        vis[n] = true;
        fibo(n - 1);
        fibo(n - 2);
        dp[n] = { dp[n - 1].first + dp[n - 2].first,dp[n - 1].second + dp[n - 2].second };
        return;
    }
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T, N;
	cin >> T;
    vector<int>input(T);
    dp[0].first = 1;
    dp[1].second = 1;
    vis[0] = true, vis[1] = true;
    int MAX = 0;
    for (int i = 0;i < T;i++) {
        cin >> input[i];
        MAX = MAX > input[i] ? MAX : input[i];
    }

    for (int i = 2;i <= MAX;i++) {
        fibo(i);
    }

    for (int i = 0;i < T;i++)
        cout << dp[input[i]].first << " " << dp[input[i]].second << "\n";
}