#include<iostream>
#include<vector>
#define min(x,y) (x<y?x:y)
using namespace std;

vector<vector<int>>v;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, M, x, y;
	cin >> N >> M;
	v.resize(N);

	for (int i = 0;i < M;i++) {
		cin >> x >> y;
		v[x - 1].push_back(y - 1);
		v[y - 1].push_back(x - 1);
	}

	int res = 1987654321;
	for (int a = 0;a < N;a++) { //첫번째친구 A
		if (v[a].size() < 2) continue;
		vector<bool>vis(N, false);
		for (auto k : v[a])
			vis[k] = true;

		for (auto b : v[a]) { //두번째친구 B
			for (auto c : v[b]) { //세번째친구 C
				if (b < c && vis[c])
					res = min(res, v[a].size() + v[b].size() + v[c].size() - 6);
			}
		}
	}

	if (res == 1987654321)
		cout << -1;
	else
		cout << res;
}