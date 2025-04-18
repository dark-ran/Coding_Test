#include<iostream>
#include<vector>

using namespace std;

vector<int>ve;

int find(int x) {
	if (ve[x] == x) return x;
	else return ve[x] = find(ve[x]);
}

void Union(int x, int y) {
	int nx = find(x);
	int ny = find(y);
	if (nx < ny) ve[ny] = nx;
	else ve[nx] = ny;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, m = 0;
	cin >> N >> M;
	ve.resize(N + 1);
	for (int i = 1; i <= N; i++) ve[i] = i;
	int u, v;
	while (M--) {
		cin >> u >> v;
		if (find(u) == find(v)) {
			m++;
			continue;
		}
		Union(u, v);
	}
	int res = 0;
	for (int j = 1; j <= N; j++)
		if (ve[j] == j) res++;
	cout << res + m - 1;
}