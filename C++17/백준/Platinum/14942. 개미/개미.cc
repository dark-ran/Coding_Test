#include<iostream>
#include<vector>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int a, int b) :to(a), cost(b) {}
};	

int N;
vector<int>energy;
vector<vector<Edge>>graph;
vector<int>par, parcost;

void dfs(int node, int p) {
	for (const auto& a : graph[node]) {
		if (a.to == p) continue;
		par[a.to] = node;
		parcost[a.to] = a.cost;
		dfs(a.to, node);
	}
}

int func(int node, int hp) {
	int cur = node;
	while (cur != 1) {
		int p = par[cur];
		int cost = parcost[cur];
		if (hp < cost) return cur; //비용 부족
		hp -= cost;
		cur = p;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> N;
	energy.resize(N + 1);
	par.resize(N + 1);
	parcost.resize(N + 1);
	graph.resize(N + 1);

	for (int i = 1;i <= N;i++)
		cin >> energy[i];
	for (int i = 0;i < N - 1;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	par[1] = 0;
	parcost[1] = 0;
	dfs(1, 0);
	for (int i = 1;i <= N;i++)
		cout << func(i, energy[i]) << "\n";
}