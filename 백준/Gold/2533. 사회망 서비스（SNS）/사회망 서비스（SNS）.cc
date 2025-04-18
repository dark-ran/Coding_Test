#include<iostream>
#include<vector>

using namespace std;

int N, cnt = 0;
vector<vector<int>>ve;
vector<bool>visited;

bool dfs(int idx) {
	int sum = 0;
	visited[idx] = true;
	for (int i = 0; i < ve[idx].size(); i++) {
		int nex = ve[idx][i];
		if (!visited[nex])
			sum += dfs(nex); //논얼리어답터면 값 추가
	}
	if (ve[idx].size() == 0) return true; //가장 깊은(리프)는 얼리어답터 아님

	if (sum != 0) { //주변에 논얼리어답터가 하나라도 있으면 얼리어답터로
		cnt++;
		return false;  //얼리어답터
	}
	return true; //논얼리어답터
}

void Input() {
	int u, v;
	cin >> N;
	ve.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
}

void Solve() {
	dfs(1);
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Input();
	Solve();
}