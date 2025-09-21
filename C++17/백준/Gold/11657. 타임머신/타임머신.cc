#include<iostream>
#include<vector>
#define pii pair<int,int>
#define INF 1'876'543'210
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> arr(N);
    for (int i = 0; i < M; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        arr[s - 1].push_back({ e - 1, v });
    }

    vector<long long> dis(N, INF);
    dis[0] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (dis[j] == INF) continue;
            for (auto& edge : arr[j]) {
                int next = edge.first;
                int cost = edge.second;
                if (dis[next] > dis[j] + cost) {
                    dis[next] = dis[j] + cost;
                }
            }
        }
    }

    for (int j = 0; j < N; j++) {
        if (dis[j] == INF) continue;
        for (auto& edge : arr[j]) {
            int next = edge.first;
            int cost = edge.second;
            if (dis[next] > dis[j] + cost) {
                cout << "-1";
                return 0;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (dis[i] == INF) cout << "-1\n";
        else cout << dis[i] << "\n";
    }
}