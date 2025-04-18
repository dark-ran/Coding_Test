#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int R, C;
vector<vector<char>>v;
vector<vector<bool>>check;
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };

void INPUT() {
	cin >> R >> C;
	v.resize(R);
	check.resize(R, vector<bool>(C, false));
	char a;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a;
			v[i].push_back(a);
		}
	}
}

void SOL() {
	int sum[2] = { 0,0 };
	queue<pair<int, int>>q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (check[i][j] || v[i][j] == '#') continue;
			int sheep = 0;
			int wolf = 0;
			q.push({ i,j });
			check[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (v[x][y] == 'v') wolf++;
				else if (v[x][y] == 'o') sheep++;
				for (int k = 0; k < 4; k++) {
					int cx = x + nx[k];
					int cy = y + ny[k];
					if (cx < 0 || cx >= R || cy < 0 || cy >= C || check[cx][cy] || v[cx][cy]== '#') continue;
					check[cx][cy] = true;
					q.push({ cx,cy });
				}
			}
			if (sheep > wolf) sum[0] += sheep;
			else sum[1] += wolf;
		}
	}
	cout << sum[0] << " " << sum[1];
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	INPUT();
	SOL();
}