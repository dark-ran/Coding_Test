#include<iostream>
#include<queue>

using namespace std;

short check[301][301];
queue<pair<int, int>>q;
int nx[8] = { -2,-1,1,2,2,1,-1,-2 };
int ny[8] = { 1,2,2,1,-1,-2,-2,-1 };

void Init() {
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int cx = x + nx[i], cy = y + ny[i];
			if (cx < 0 || cx >= 300 || cy < 0 || cy >= 300 || check[cx][cy]) continue;
			q.push({ cx,cy });
			check[cx][cy] = check[x][y] + 1;
		}
	}
	check[0][0] = 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	Init(); 
	int T, l, x, y, cx, cy, dx, dy;
	cin >> T;
	while (T--) {
		cin >> l >> x >> y >> cx >> cy;
		dx = x > cx ? x - cx : cx - x;
		dy = y > cy ? y - cy : cy - y;

		if (l == 4) {
			if ((dx == 0 && dy == 3) || (dx == 3 && dy == 0)) {
				cout << "5\n";
				continue;
			}
		}

		if (dx == 1 && dy == 1) {
			int k;
			for (k = 0; k < 8; k++) {
				int kx = x + nx[k], ky = y + ny[k];
				if (kx >= 0 && kx < l && ky >= 0 && ky < l) {
					int ddx = kx > cx ? kx - cx : cx - kx;
					int ddy = ky > cy ? ky - cy : cy - ky;
					if (ddx * ddy == 2) {
						cout << "2\n";
						break;
					}
				}
			}
			if (k == 8) cout << "4\n";
		}
		else cout << check[dx][dy]<< "\n";
	}
}