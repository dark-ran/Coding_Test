#include<iostream>
#include<queue>
using namespace std;
int n, m, v;
int u, y;
bool adj[1001][1001]{ false };//간선정보 넣기
bool vis[1001]{ false };//dfs에서 방문한 곳 확인
bool vis1[1001]{ false };//dfs에서 방문한 곳 확인

void dfs(int a) { 
	cout << a << " ";
	vis[a] = true;
	for (int i = 1; i <= n; i++) {
		if (adj[a][i] && !vis[i])//간선이 연결되어있고 방문한 적이 없다면
			dfs(i);
	}
}

void bfs(int a) {
	queue<int>q;
	q.push(a); //시작 지점을 큐에 넣기
	vis1[a] = true; //방문한 흔적 남기기
	while (!q.empty()) { //큐에 값이 들어있다면
		a = q.front(); //맨 앞에 있는 값을 가져오고 제거
		q.pop(); 
		cout << a << " ";
		for (int i = 1; i <= n; i++) {
			if (adj[a][i] && !vis1[i]) {
				q.push(i); //현재 값과 연결되어있고 방문하지 않은 값 넣기
				vis1[i] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> u >> y;
		adj[u][y] = true;
		adj[y][u] = true;
	}
	dfs(v);
	cout << "\n";
	bfs(v);
}