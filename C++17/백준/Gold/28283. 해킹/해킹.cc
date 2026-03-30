#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 1987654321
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M, X, Y, s, e;
	cin >> N >> M >> X >> Y;
	vector<ll>money(N);
	vector<vector<int>>v(N);
	vector<int>vacine(N);
	for (int i = 0;i < N;i++) {
		cin >> money[i];
		vacine[i] = INF;
	}

	for (int i = 0;i < M;i++) {
		cin >> s >> e;
		v[s - 1].push_back(e - 1);
		v[e - 1].push_back(s - 1);
	}

	queue<int>q;
	for (int i = 0;i < Y;i++) {
		cin >> s;
		q.push(s - 1);
		vacine[s - 1] = 0;
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : v[cur]) {
			if (vacine[nxt] == INF) {
				vacine[nxt] = vacine[cur] + 1;
				q.push(nxt);
			}
		}
	}

	for (int i = 0;i < N;i++) {
		if (vacine[i] == INF && money[i] > 0) {
			cout << -1;
			return 0;
		}
		money[i] *= vacine[i];
	}

	sort(money.begin(), money.end(), greater<>());
	ll sum = 0;
	for (int i = 0;i < X;i++)
		sum += money[i];
	cout << sum;
}
