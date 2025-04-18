#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T, N, M;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		vector<pair<int, int>>lis[21]; //간선 저장
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			lis[x].push_back({ y,z });
			lis[y].push_back({ x,z });
		}

		int rec[21]; //지금 노드 이전의 노드 기록
		fill(rec, rec + 21, -1);
		vector<int> visited(21,10000);

		//DFS
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // { 비용 , 현재위치 }
		pq.push({ 0,0 });
		int dist[21];
		fill(dist, dist + M + 1, 10000);
		dist[0] = 0;
		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();

			if (visited[cur] < cost) continue; //이전 방문이 더 비용이 작다면

			if (cur == M - 1) break; //최고위 만나면 스탑

			for (int i = 0; i < lis[cur].size(); i++) { //거리 값 갱신
				int next = lis[cur][i].first;
				int ncost = lis[cur][i].second;
				if (dist[next] > cost + ncost) {
					dist[next] = cost + ncost;
					rec[next] = cur;
					pq.push({ cost + ncost,next });
				}
			}
		}

		cout << "Case #" << t << ": ";
		if (dist[M - 1] == 10000)
			cout << "-1";
		else {
			vector<int>arr;
			int i = M - 1;
			while (i != 0) {
				arr.push_back(i);
				i = rec[i];
			}
			arr.push_back(0);
			for (int i = arr.size() - 1; i >= 0; i--) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	}
}