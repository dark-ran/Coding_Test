#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>v(N + 1);
	vector<int>deg(N + 1);
	for (int i = M; i > 0; i--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		deg[y]++;
	}
	queue<int>q;
	for (int i = 1; i <= N; i++)
		if (deg[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();;
		q.pop();
		cout << cur << " ";
		while (!v[cur].empty()) {
			deg[v[cur].back()]--;
			if (deg[v[cur].back()] == 0)
				q.push(v[cur].back());
			v[cur].pop_back();
		}
	}
}