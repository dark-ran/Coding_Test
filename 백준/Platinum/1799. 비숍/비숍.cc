#include<stdio.h>
#include<vector>

using namespace std;

int N, res = 0;
vector<bool>vis;
vector<vector<pair<int, int>>>v1;
vector<vector<pair<int, int>>>v2;

void check(int i, int cnt, vector<vector<pair<int, int>>>& b) {
	if (i == 2 * N - 1) {
		res = max(res, cnt);
		return;
	}
	bool flag = false;
	for (auto a : b[i]) {
		if (vis[a.first - a.second + N - 1]) continue;
		vis[a.first - a.second + N - 1] = true;
		check(i + 1, cnt + 1, b);
		vis[a.first - a.second + N - 1] = false;
		flag = true;
	}
	if (!flag) check(i + 1, cnt, b);
}

int main() {
	scanf("%d", &N);
	v1.resize(2 * N - 1);
	v2.resize(2 * N - 1);
	vis.resize(2 * N - 1, false);
	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &x);
			if (x) {
				if((i+j)%2==1) v1[i + j].push_back({ i,j });
				else v2[i + j].push_back({ i,j });
			}
		}
	}
	check(0, 0, v1);
	int first = res;
	res = 0;
	check(0, 0, v2);
	printf("%d", first + res);
}