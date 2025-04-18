#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	int n, m, ans = 0, x = 0, y = 0;
	int km, kmh, now = 0;
	vector<pair<int, int>> road, v;
	scanf("%d%d", &n, &m);

	scanf("%d%d", &km, &kmh);
	road.push_back({ km, kmh });
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &km, &kmh);
		road.push_back(make_pair(road[i - 1].first + km, kmh));
	}

	scanf("%d%d", &km, &kmh);
	v.push_back({ km, kmh });
	for (int i = 1; i < m; i++) {
		scanf("%d%d", &km, &kmh);
		v.push_back({ v[i - 1].first + km, kmh });
	}

	for (int i = 1; i <= 100; i++) {
		if (road[x].second < v[y].second && v[y].second - road[x].second > ans) {
			ans = v[y].second - road[x].second;
		}
		if (i == 100) break;
		if (v[y].first == i) y++;
		if (road[x].first == i) x++;
	}
	printf("%d", ans);
}