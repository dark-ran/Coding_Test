#include<iostream>
#include<vector>

using namespace std;

vector<int>par;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void Union(int x, int y) {
	x = find(par[x]);
	y = find(par[y]);
	if (x != y)
	{
		if (x >= y)
			par[x] = y;
		else
			par[y] = x;
	}
}

bool check(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	par.resize(N);
	for (int i = 0;i < N;i++)
		par[i] = i;
	for (int i = 0;i < M;i++) {
		int x, y;
		cin >> x >> y;
		if (check(x, y)) {
			cout << i + 1 << flush;
			return 0;
		}
		Union(x, y);
	}
	cout << 0 << flush;
	return 0;
}