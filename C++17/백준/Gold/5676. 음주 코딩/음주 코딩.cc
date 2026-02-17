#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K;
	while (cin >> N >> K) {
		int h = (int)ceil(log(N) / log(2));
		int size = 1 << h;
		vector<int>tree(size << 1);
		for (int i = 0;i < N;i++) {
			cin >> tree[size + i];
			if (tree[size + i] > 0) tree[size + i] = 1;
			else if (tree[size + i] < 0)tree[size + i] = -1;
		}
		for (int i = size + N;i < 2 * size;i++)
			tree[i] = 1;

		for (int i = size - 1;i > 0;i--)
			tree[i] = tree[i << 1] * tree[(i << 1) | 1];

		for (int i = 0;i < K;i++) {
			char c;
			int x, y;
			cin >> c >> x >> y;
			if (c == 'C') {
				int idx = size + x - 1;
				if (tree[idx] * y > 0) continue; //same sign
				if (tree[idx] == 0 && y == 0) continue;

				tree[idx] = y;
				if (tree[idx] > 0)tree[idx] = 1;
				else if (tree[idx] < 0)tree[idx] = -1;

				y = tree[idx];
				for (idx >>= 1;idx > 0;idx >>= 1) //modify
					tree[idx] = tree[idx << 1] * tree[(idx << 1) | 1];
			}
			else {
				int res = 1;
				x += size - 1;
				y += size - 1;
				while (x <= y) {
					if (x & 1)res *= tree[x];
					if (!(y & 1))res *= tree[y];
					x = (x + 1) >> 1;
					y = (y - 1) >> 1;
				}
				if (res == 0) cout << res;
				else cout << (res > 0 ? '+' : '-');
			}
		}
		cout << "\n";
	}
}