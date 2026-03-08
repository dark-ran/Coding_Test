#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>>q[20003];
int d[20003];
int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int v, e, k, V, u, w;
	cin >> v >> e >> k;
	fill(d, d + v + 1, 100000000);
	for (int i = 0; i < e; i++) {
		cin >> u >> V >> w;
		q[u].push_back({ V,w });
	}
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	d[k] = 0;
	pq.push({ d[k],k});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : q[cur.second]) {
			if (d[nxt.first] <= d[cur.second] + nxt.second) 
				continue;
			d[nxt.first] = d[cur.second] + nxt.second;
			pq.push({ d[nxt.first],nxt.first });
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == 100000000) cout << "INF\n";
		else cout << d[i] << "\n";
	}
}