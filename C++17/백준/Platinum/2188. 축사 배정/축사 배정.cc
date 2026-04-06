#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>v;
vector<int>check;//이 축사에 어떤 소가 있는지
vector<bool>vis;//이번에 방문했는지

bool dfs(int cow) {
	for (auto barn : v[cow]) { //방문하는 축사
		if (vis[barn]) continue; //이미 이 축사를 방문했다면
		vis[barn] = true;
		if (check[barn] == -1 || dfs(check[barn])) { //소가 배정안되어있거나 다른 곳으로 옮길 수 있을 때
			check[barn] = cow;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, M, x;
	cin >> N >> M;
	v.resize(N);
	check.resize(M,-1);
	for (int i = 0;i < N;i++) {
		cin >> x;
		v[i].resize(x);
		for (int j = 0;j < x;j++) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}

	int res = 0;
	for (int i = 0;i < N;i++) {
		vis.assign(M, false);
		if (dfs(i))
			res++;
	}
	cout << res;
}