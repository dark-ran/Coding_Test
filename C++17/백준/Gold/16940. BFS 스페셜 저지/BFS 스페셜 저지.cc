#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int>arr[100'001];
int N, ans[100'001];
bool vis[100'001];
queue<int>q;

bool bfs() {
	static int idx = 0;
	if (ans[0] != 0) {
		return false;
	}

	q.push(0);
	vis[0] = true;
	int cur, nxt = ans[++idx];
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		while (true) {
			if (vis[nxt]) return false;
			if (!binary_search(arr[cur].begin(), arr[cur].end(), nxt)) break;
			q.push(nxt);
			vis[nxt] = true;
			nxt = ans[++idx];
			if (idx >= N) return true;
		}
	}
	return idx == N;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int a, b;
	cin >> N;
	for (int i = 1;i < N;i++) {
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0;i < N;i++) {
		cin >> ans[i];
		ans[i]--;
		sort(arr[i].begin(), arr[i].end());
	}
	cout << bfs();
}