#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, ma, cnt, res;
vector<vector<int>>v;
vector<vector<bool>>check;
queue<pair<int, int>>q;
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };

void INPUT() {
	ma = 0;
	cin >> N;
	v.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			ma = ma > v[i][j] ? ma : v[i][j];
		}
	}
}

void SOL() {
	res = 1;
	for (int h = 1; h < ma; h++) {
		check = vector<vector<bool>>(N, vector<bool>(N, false));
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] || v[i][j] <= h) continue;
				q.push({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int cx = x + nx[k];
						int cy = y + ny[k];
						if (cx < 0 || cx >= N || cy < 0 || cy >= N || v[cx][cy] <= h || check[cx][cy]) continue;
						q.push({ cx,cy });
						check[cx][cy] = true;
					}
				}
				cnt++;
			}
		}
		res = res > cnt ? res : cnt;
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	INPUT();
	SOL();
}