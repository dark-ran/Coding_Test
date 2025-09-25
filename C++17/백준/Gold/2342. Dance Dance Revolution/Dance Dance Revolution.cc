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
				cur[a][j] = (cur[a][j] == 0 ? pre[i][j] + weight[i][a] : min(cur[a][j], pre[i][j] + weight[i][a]));
				cur[i][a] = (cur[i][a] == 0 ? pre[i][j] + weight[j][a] : min(cur[i][a], pre[i][j] + weight[j][a]));
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