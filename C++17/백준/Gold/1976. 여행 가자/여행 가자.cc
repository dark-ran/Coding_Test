#include<iostream>
#include<vector>

using namespace std;

vector<int>v;

int find(int x) {
	if (v[x] == x) return x;
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
	int N, M, x, y;
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) v[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (x == 1) Union(i, j);
		}
	}
	cin >> x;
	y = find(x);
	for (int i = 1; i < M; i++) {
		cin >> x;
		if (find(x) != y) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}