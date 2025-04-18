#include<iostream>
#include<queue>

using namespace std;

int arr[10001];
int res[10001];
bool vis[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
		vis[arr[i]] = true;
		for (int j = 0; j < i; j++) {
			if (arr[i] + arr[j] > N || vis[arr[i] + arr[j]]) continue;
			vis[arr[i] + arr[j]] = true;
		}
	}

	int a = 0;
	for (int i = 1; i <= N; i++) {
		if (vis[i])
			res[a++] = i;
	}
	fill(vis, vis + N + 1, false);
	queue<pair<int,int>>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < a; i++) {
			if (res[i] + cur.second > N || vis[res[i] + cur.second]) continue;
			if (res[i] + cur.second == N) {
				cout << cur.first + 1;
				return 0;
			}
			q.push({ cur.first + 1,cur.second + res[i] });
			vis[cur.second + res[i]] = true;
		}
	}
	cout << "-1";
}