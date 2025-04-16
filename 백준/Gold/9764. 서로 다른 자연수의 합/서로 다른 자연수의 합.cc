#include<stdio.h>
#include <queue>

using namespace std;

int dp[2001];
const int mod = 100999;

int main() {
    int T, MAX = 0;
    scanf("%d", &T);
    queue<int> q;

    while (T--) {
        int x;
        scanf("%d", &x);
        q.push(x);
        if (x > MAX) MAX = x;
    }

    dp[0] = 1;
    for (int j = 1; j <= MAX; j++) {
        for (int i = MAX; i >= j; i--) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    while (!q.empty()) {
        int N = q.front();
        q.pop();
        printf("%d\n", dp[N]);
    }
}