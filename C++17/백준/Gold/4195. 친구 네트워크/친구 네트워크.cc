#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int sizes[200002];
int link[200002];

int find(int x) {
	if (link[x] == x) return x;
	return link[x] = find(link[x]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b];
		link[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T, F, x, y;
	cin >> T;

	string a, b;

	while(T--) {
		cin >> F;
		for (int i = 0; i < 200002; i++) {
			sizes[i] = 1;
			link[i] = i;
		}
		map<string, int> map;
		int k = 1;

		for (int i = 0; i < F; i++) {
			cin >> a >> b;

			if (map.count(a) == 0) map[a] = k++;
			if (map.count(b) == 0) map[b] = k++;

			Union(map[a], map[b]);

			x = find(map[a]);
			y = find(map[b]);

			cout << max(sizes[x], sizes[y]) << '\n';
		}
	}
}