#include<iostream>
#include<vector>
#define INF 1987654321
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n, k, s, x, y;
	cin >> n >> k;
	vector<vector<int>>v(n, vector<int>(n, INF)); //양수면 시간순
	for (int i = 0;i < k;i++) {
		cin >> x >> y; //x가 먼저, y가 나중
		v[x - 1][y - 1] = -1;
		v[y - 1][x - 1] = 1;
	}

	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (v[i][k] == INF || v[k][j] == INF) continue;
				if (v[i][k] < 0 && v[k][j] > 0) continue;
				if (v[i][k] > 0 && v[k][j] < 0) continue;
				v[i][j] = v[i][k];
			}
		}
	}

	cin >> s;

	for (int i = 0;i < s;i++) {
		cin >> x >> y;
		if (v[x - 1][y - 1] == INF) cout << 0 << "\n";
		else if (v[x - 1][y - 1] > 0) cout << 1 << "\n";
		else cout << -1 << "\n";
	}
}