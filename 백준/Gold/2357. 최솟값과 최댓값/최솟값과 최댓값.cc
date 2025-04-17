#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void init(vector<int>& tree_max, vector<int>&tree_min, vector<int>& arr, int size, int N) {
	for (int i = 1; i <= N; i++) {
		tree_max[i + size] = arr[i - 1];
		tree_min[i + size] = arr[i - 1];
	}
	for (int i = size - 1; i; i--) {
		pair<int, int>left = { tree_max[i * 2],tree_min[i * 2] ? tree_min[i * 2] : 1987654321 };
		pair<int, int>right = { tree_max[i * 2 + 1],tree_min[i * 2 + 1] ? tree_min[i * 2 + 1] : 1987654321 };
		tree_max[i] = max(left.first, right.first);
		tree_min[i] = min(left.second, right.second);
	}
}

pair<int, int>query(int x,int y, int size, vector<int>& tree_max, vector<int>& tree_min) {
	x += size, y += size;
	int Max = 0;
	int Min = 1987654321;
	while (x <= y) {
		if (x & 1) {
			Max = max(Max, tree_max[x]);
			Min = min(Min, tree_min[x]);
			x++;
		}
		if (~y & 1) {
			Max = max(Max, tree_max[y]);
			Min = min(Min, tree_min[y]);
			y--;
		}
		x >>= 1;
		y >>= 1;
	}
	return { Min,Max };
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	int size = 1 << ((int)ceil(log2(N)));
	vector<int>tree_max(size << 1);
	vector<int>tree_min(size << 1);
	init(tree_max, tree_min, arr, size, N);
	while (M--) {
		int x, y;
		cin >> x >> y;
		pair<int, int>a = query(x, y, size, tree_max, tree_min);
		cout << a.first << " " << a.second << "\n";
	}
}