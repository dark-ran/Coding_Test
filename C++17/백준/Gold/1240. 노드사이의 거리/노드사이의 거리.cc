#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>

using namespace std;

vector<vector<pii>>v1; //{node,dis}
vector<bool>vis;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	v1.resize(N);
	vis.resize(N);
	for (int i = 1;i < N;i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v1[x - 1].push_back({ y - 1,z });
		v1[y - 1].push_back({ x - 1,z });
	}

	while (M--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		for (int i = 0;i < N;i++)
			vis[i] = false;
		priority_queue<pii, vector<pii>, greater<pii>>pq; //{length, node}
		pq.push({ 0,x });

		while (!pq.empty()) {
			pii cur = pq.top();
			pq.pop();
			if (cur.second == y) {
				cout << cur.first << "\n";
				break;
			}
			if (vis[cur.second])
				continue;
			vis[cur.second] = true;
			for (auto a : v1[cur.second]) {
				if (vis[a.first]) 
					continue;
				pq.push({ cur.first + a.second,a.first });
			}
		}
	}
}