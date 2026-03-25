#include<iostream>
#include<vector>
#define ll long long
using namespace std;

ll MAX = 1e18;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	ll T, N, K, a, b, S;
	cin >> T;
	while (T--) {
		cin >> N >> K >> a >> b;
		vector<ll>cost(K + 1);
		cost[0] = 0;
		for (int i = 1;i <= K;i++)
			cost[i] = MAX;
		for (int i = 0;i < N;i++) {
			cin >> S;
			ll c = (S == 1 ? 0 : a * (S - 1) * (S - 1) + b);
			for (int j = K;j >= 0;j--) {
				if (cost[j] == MAX)
					continue;
				int nx = min(K, j + S);
				cost[nx] = min(cost[nx], cost[j] + c);
			}
		}
		cout << cost[K] << "\n";
	}
}