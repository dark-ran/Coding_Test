#include<iostream>
#include<vector>

using namespace std;

vector<int>v;

int find(int x) {
	if (v[x] == x)
		return x;
	return v[x] = find(v[x]);
}

void Union(int x, int y) {
	int dx = find(x);
	int dy = find(y);
	if (dx > dy) v[dx] = dy;
	else v[dy] = dx;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i <= N; i++)
		v[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			Union(b, c);
		}
		else {
			if (find(b) == find(c)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}