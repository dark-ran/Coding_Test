#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, T = 0, res = 0;
int a[8][8];
int b[8][8];
int c[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>>space; //빈공간 저장
pair<int, int> virus[100]; //바이러스 저장

void mapcopy(int(*x)[8], int(*y)[8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			y[i][j] = x[i][j];
		}
	}
}

void check() {
	int cnt = 0;
	mapcopy(b, c);
	int idx = 0;
	int t = T;
	while (idx < t) {
		int x = virus[idx].first;
		int y = virus[idx].second;
		idx++;
		for (int i = 0; i < 4; i++) {
			int cur_x = x + dx[i];
			int cur_y = y + dy[i];
			if (!c[cur_x][cur_y] && cur_x >= 0 && cur_y >= 0 && cur_x < N && cur_y < M) { //빈공간이라면
				c[cur_x][cur_y] = 2;
				virus[t++] = { cur_x,cur_y };
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!c[i][j])
				cnt++;
		}
	}
	res = res > cnt ? res : cnt;
}

void wall(int num, int x) {
	if (num == 3) {
		check();
		return;
	}
	for (int i = x + 1; i < space.size(); i++) {
		int x = space[i].first;
		int y = space[i].second;
		b[x][y]++;
		wall(num + 1, i);
		b[x][y]--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (!a[i][j])
				space.push_back({ i,j });
			else if (a[i][j] == 2)
				virus[T++] = { i,j };
		}
	}

	mapcopy(a, b);
	for (int i = 0; i < space.size(); i++) {
		int x = space[i].first;
		int y = space[i].second;
		b[x][y]++;
		wall(1, i);
		b[x][y]--;
	}
	cout << res;
}