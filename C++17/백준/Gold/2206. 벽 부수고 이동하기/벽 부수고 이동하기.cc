#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

string arr[1001];
bool visited[1001][1001][2];

struct s{
	int x, y, t, a; 
};


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<pair<int,int>>v;
	queue<s>q;

	for (int i = 0; i < N; i++) {
			cin >> arr[i];
	}

	q.push({ 0,0,1,0 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (cur.x == N - 1 && cur.y == M - 1) {
			cout << cur.t;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y][cur.a]) {
				if (arr[x][y] == '0') {
					q.push({ x,y,cur.t + 1,cur.a });
					visited[x][y][cur.a] = true;
				}
				else { //다음 길이 벽이면
					if (cur.a == 0) {
						q.push({ x,y,cur.t + 1,cur.a+1 });
						visited[x][y][cur.a + 1] = true;
					}
				}
			}
		}
	}
	cout << "-1";
}
