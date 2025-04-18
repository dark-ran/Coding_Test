#include<iostream>
#include<queue>

using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int M, N, K;
	cin >> M >> N >> K;
	queue<pair<int, int>>q;
	priority_queue<int, vector<int>, greater<int>>pq;
	int x, y, a, b;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> a >> b;
		for (int j = x; j < a; j++) {
			for (int k = y; k < b; k++) {
				arr[k][j] = -1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] || arr[i][j] == -1) continue;
			q.push({ i,j });
			visited[i][j] = true;
			int sum = 0;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				sum++;
				for (int k = 0; k < 4; k++) {
					int x = cur.first + dx[k];
					int y = cur.second + dy[k];
					if (x < 0 || x >= M || y < 0 || y >= N || visited[x][y] || arr[x][y] == -1) continue;
					q.push({ x,y });
					visited[x][y] = true;
				}
			}
			pq.push(sum);
		}
	}

	cout << pq.size() << "\n";
	while (!pq.empty()) {
		cout << pq.top()<<" ";
		pq.pop();
	}
}