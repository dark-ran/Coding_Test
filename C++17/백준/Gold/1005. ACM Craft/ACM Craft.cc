#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T, N, K, target;
    cin >> T;
    int arr[1001], dp[1001], degree[1001];
    vector<int> v[1001];

    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            v[i].clear();
            degree[i] = 0;
            dp[i] = 0;
        }

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            v[x - 1].push_back(y - 1);
            degree[y - 1]++;
        }

        cin >> target;
        target--;

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (degree[i] == 0) {
                q.push(i);
                dp[i] = arr[i];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : v[cur]) {
                dp[next] = max(dp[next], dp[cur] + arr[next]);
                if (--degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[target] << '\n';
    }
}