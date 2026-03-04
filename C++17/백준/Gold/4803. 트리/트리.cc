#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool istree(vector<vector<int>>& branch, int st, vector<int>& vis) {
	queue<int>q;
	q.push(st);
	vis[st] = 2;
	bool flag = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto a : branch[cur]) {
			if (vis[a] == vis[cur] - 1) //부모인경우
				continue;
			else if (vis[a] != 0) {//방문을 한 노드인데 부모가 아닌경우
				flag = false;
				continue;
			}
			vis[a] = vis[cur] + 1;
			q.push(a);
		}
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int N, M, CASE = 1;
	while (cin >> N >> M) {
		if (N == 0 && M == 0) return 0;
		vector<int>vis(N);
		vector<vector<int>>branch(N);
		for (int i = 0;i < M;i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			branch[x].push_back(y);
			branch[y].push_back(x);
		}

		int ans = 0;
		for (int i = 0;i < N;i++)
			if (!vis[i] && istree(branch, i, vis)) ans++;
		
		cout << "Case " << CASE++ << ": ";
		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " trees.\n";
	}
}