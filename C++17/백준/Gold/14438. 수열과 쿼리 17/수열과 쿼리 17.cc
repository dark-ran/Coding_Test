#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int h = (int)(ceil(log2(N)));
	int size = (1 << h);
	vector<int>tree(size << 1);
	for (int i = 0; i < N; i++) {
		cin >> tree[size + i];
	}
	for (int i = N; i < size; i++) {
		tree[size + i] = 1987654321;
	}
	for (int i = size - 1; i > 0; i--) {
		tree[i] = tree[i << 1] < tree[i << 1 | 1] ? tree[i << 1] : tree[i << 1 | 1];
	}
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			tree[size + b - 1] = c;
			for (int i = ((size + b - 1) >> 1); i > 0; i >>= 1) {
				int min = tree[i << 1] < tree[i << 1 | 1] ? tree[i << 1] : tree[i << 1 | 1];
				if (tree[i] != min) {
					tree[i] = min;
				}
				else
					break;
			}
		}
		else {
			int MIN = 1987654321;
			int l = size + b - 1;
			int r = size + c - 1;
			while (l <= r) {
				if (l & 1)
					MIN = MIN < tree[l] ? MIN : tree[l];
				if (!(r & 1))
					MIN = MIN < tree[r] ? MIN : tree[r];
				l++;
				r--;
				l >>= 1;
				r >>= 1;
			}
			cout << MIN << "\n";
		}
	}
}