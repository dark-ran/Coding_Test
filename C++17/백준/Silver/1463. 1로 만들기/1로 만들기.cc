#include<iostream>
#include<queue>

using namespace std;

bool vis[1000000]{ false };

int bfs(int i) {
	queue<pair<int, int>>q;
	q.push({ i,0 });
	int cur, cnt;
	while (!q.empty()) {
		cur = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (cur == 1)
			return cnt;
		if (cur % 3 == 0 && !vis[cur / 3]) {
			q.push({ cur / 3,cnt + 1 });
			vis[cur / 3] = true;
		}
		if (cur % 2 == 0 && !vis[cur / 2]) {
			q.push({ cur / 2,cnt + 1 });
			vis[cur / 2] = true;
		}
		if (!vis[cur - 1]) {
			q.push({ cur - 1,cnt + 1 });
			vis[cur - 1] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << bfs(n);
}