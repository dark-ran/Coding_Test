#include<stdio.h>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

int arr[101][101][101];
int m, n, h, num = 0, max_ = 1;

queue<tuple<int, int, int>>q;

void bfs() {
	int nx[6] = { 1,0,-1,0,0,0 };
	int ny[6] = { 0,-1,0,1,0,0 };
	int nz[6] = { 0,0,0,0,1,-1 };
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int k = 0; k < 6; k++) {
			int ix = x + nx[k];
			int iy = y + ny[k];
			int iz = z + nz[k];
			if (ix >= n || ix < 0 || iy >= m || iy < 0 || iz >= h || iz < 0) continue;

			if (arr[ix][iy][iz] == 0) { //안익었다면
				arr[ix][iy][iz] = arr[x][y][z] + 1;
				q.push({ ix,iy,iz });
				num--;
			}

			else if (arr[ix][iy][iz] > 1) {//이미 값이 있다면
				if (arr[ix][iy][iz] > arr[x][y][z] + 1) {
					arr[ix][iy][iz] = arr[x][y][z] + 1;
					q.push({ ix,iy,iz });
				}
			}

			max_ = max(max_, arr[ix][iy][iz]);
		}
	}
}

int main() {
	scanf("%d%d%d", &m, &n, &h);
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) { //Input
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 0) num++;
				else if (arr[i][j][k] == 1) q.push({ i,j,k }); //시작지점들을 전부 넣어서 시간단축
			}
		}
	}

	if(num!=0)
		bfs();

	if (num != 0) { //0이 제거 안되었다면
		printf("-1");
		return 0;
	}

	printf("%d", max_ - 1);
}