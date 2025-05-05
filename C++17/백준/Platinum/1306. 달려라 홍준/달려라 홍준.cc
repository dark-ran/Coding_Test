#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void init(int size, vector<int>&tree) {
	for (int i = size - 1; i; i--) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	return;
}

void modify(int size, int idx, int value, vector<int>& tree) {
	idx += size;
	tree[idx] = value;
	idx >>= 1;
	while (idx) {
		int new_val = max(tree[idx * 2], tree[idx * 2 + 1]);
		if (tree[idx] == new_val) return;
		tree[idx] = new_val;
		idx >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M, x;
	cin >> N >> M;
	int size = 1 << (int)ceil(log2(2 * M - 1));
	vector<int>tree(size * 2);
	for (int i = 0; i < 2 * M - 1; i++) cin >> tree[size + i];
	init(size, tree);
	cout << tree[1] << " ";
	for (int i = 0; i < N - 2 * M + 1; i++) {
		cin >> x;
		modify(size, i % (2 * M - 1), x, tree);
		cout << tree[1] << " ";
	}
}