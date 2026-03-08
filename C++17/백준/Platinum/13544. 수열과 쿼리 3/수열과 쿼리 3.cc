#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[1 << 17];
vector<int>tree[1 << 20];

void init(int node,int start,int end) {
	vector<int>& cur = tree[node];
	if (start == end) {
		cur.push_back(arr[start]);
		return;
	}
	int mid = (start + end) >> 1;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	vector<int>& l = tree[node * 2];
	vector<int>& r = tree[node * 2 + 1];
	cur.resize(l.size() + r.size());
	merge(l.begin(), l.end(), r.begin(), r.end(), cur.begin());
}

int query(int node, int start, int end, int x, int y, int k) {
	if (y < start || end < x) return 0;
	if (x <= start && end <= y) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
	int mid = (start + end) / 2;
	int left = query(node * 2, start, mid, x, y, k);
	int right = query(node * 2 + 1, mid + 1, end, x, y, k);
	return left + right;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, a = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;
	init(1, 0, n - 1);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		i ^= a;
		j ^= a;
		k ^= a;
		a = query(1, 0, n - 1, i - 1, j - 1, k);
		cout << a << "\n";
	}
}