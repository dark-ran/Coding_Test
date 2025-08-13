#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;

vector<vector<pii>>v;
bool vis[100'001];
int MAX = 0;
int node;

void dfs(int  num, int idx) {
	vis[idx] = true;
	for (pii a : v[idx]) {
		if (!vis[a.first]) {
			dfs(num + a.second, a.first);
		}
	}
	if (MAX < num) {
		MAX = num;
		node = idx;
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0;i < N - 1;i++) {
		int p, c, u;
		cin >> p >> c >> u;
		v[p - 1].push_back({ c - 1,u });
		v[c - 1].push_back({ p - 1,u });
	}

	dfs(0, 0);
	MAX = 0;
	fill(vis, vis + N + 1, false);
	dfs(0, node);
	cout << MAX;
}