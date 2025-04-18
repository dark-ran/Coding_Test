#include<iostream>

using namespace std;

bool map[50][50];

void dfs(int x, int y) {
	if (x < 0 || x >= 50 || y < 0 || y >= 50) return;
	if (!map[x][y]) return;
	map[x][y] = false;

	dfs(x + 1, y + 1);
	dfs(x + 1, y);
	dfs(x + 1, y - 1);

	dfs(x - 1, y + 1);
	dfs(x - 1, y);
	dfs(x - 1, y - 1);

	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w, h, temp;
	while (true) {
		cin >> w >> h;
		if (w == 0 || h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> temp;
				map[i][j] = temp;
			}
		}
		int tot = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!map[i][j]) continue;
				tot++;
				dfs(i, j);
			}
		}
		cout << tot << "\n";
	}
}