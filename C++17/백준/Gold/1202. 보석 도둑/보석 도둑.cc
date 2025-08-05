#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> jewel(N);
    for (int i = 0; i < N; i++) {
        cin >> jewel[i].first >> jewel[i].second;
    }

    vector<int> bag(K);
    for (int i = 0; i < K; i++) {
        cin >> bag[i];
    }

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    ll res = 0;
    int idx = 0;

    for (int i = 0; i < K; i++) {
        while (idx < N && jewel[idx].first <= bag[i]) {
            pq.push(jewel[idx++].second);
        }

        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
    }

    cout << res;
}