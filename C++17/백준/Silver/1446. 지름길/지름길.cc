#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int map[10000];

struct s {
	int start;
	int end;
	int length;
};
bool com(const s& a, const s& b) {
	return a.start < b.start;
}

int main() {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	int n, d;
	cin >> n >> d;
	int x, y, z;
	vector<s>v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		if (y > d)continue;
		if (z >= y - x) continue;
		v.push_back({ x,y,z });
	}

	sort(v.begin(), v.end(),com);

	int idx1 = 0;
	int i = 0;

	while (i <= d) {
		if (map[i] != 0) map[i] = map[i - 1] + 1 < map[i] ? map[i - 1] + 1 : map[i];
		else if (i == 0);
		else map[i] = map[i - 1] + 1;

		if (idx1 < v.size() && v[idx1].start == i) {
			if (map[v[idx1].end] == 0) map[v[idx1].end] = map[i] + v[idx1].length;
			else map[v[idx1].end] = map[v[idx1].end] < map[i] + v[idx1].length ? map[v[idx1].end] : map[i] + v[idx1].length;
			idx1++;
			continue;
		}

		i++;
	}
	cout << map[i-1];
}