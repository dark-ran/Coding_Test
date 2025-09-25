#include<iostream>
#include<queue>
#define pii pair<int,int>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

int pre[5][5];
int cur[5][5];
int weight[5][5] = { 
	{1,2,2,2,2},
	{2,1,3,4,3},
	{2,3,1,3,4},
	{2,4,3,1,3},
	{2,3,4,3,1} 
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int a;
	cin >> a;
	if (!a) {
		cout << 0 << flush;
		return 0;
	}
	pre[a][0] = 2;
	pre[0][a] = 2;
	while (true) {
		cin >> a;
		if (!a) break;

		for (int i = 0;i < 5;i++) {
			for (int j = 0;j < 5;j++) {
				if (!pre[i][j])
					continue;
				int cost1 = pre[i][j] + weight[i][a];
				if (cur[a][j] == 0 || cost1 < cur[a][j])
					cur[a][j] = cost1;

				// 오른발을 a로 이동 (j→a)
				int cost2 = pre[i][j] + weight[j][a];
				if (cur[i][a] == 0 || cost2 < cur[i][a])
					cur[i][a] = cost2;
			}
		}
		for (int i = 0;i < 5;i++)
			for (int j = 0;j < 5;j++) {
				pre[i][j] = cur[i][j];
				cur[i][j] = 0;
			}
	}
	int res = 123456789;
	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 5;j++)
			res = (pre[i][j] == 0 ? res : min(res, pre[i][j]));

	cout << res;
}