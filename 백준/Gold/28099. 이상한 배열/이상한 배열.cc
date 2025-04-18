#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int make_tree(vector<int>*v,int node,int start,int end,vector<int>&arr) {
	if (start == end) return (*v)[node] = arr[start];
	int mid = (start + end) / 2;
	int left = make_tree(v, node * 2, start, mid, arr);
	int right = make_tree(v, node * 2 + 1, mid + 1, end, arr);
	return (*v)[node] = max(left, right);
}

int query(vector<int>* v, int node, int start, int end,int x,int y) {
	if (end<x || start>y) return -1;//범위 밖
	if (start >= x && end <= y) return (*v)[node];//완벽히 범위 안
	int mid = (start + end) / 2;
	int left = query(v, node * 2, start, mid, x, y);
	int right = query(v, node * 2 + 1, mid + 1, end, x, y);
	return max(left, right);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int>v((n + 1) * 4); // 세그먼트 트리 크기를 (n + 1) * 4로 변경
		vector<pair<int, int>>c(n + 1, make_pair(0, 0));
		vector<int>arr(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (c[arr[i]].first == 0)
				c[arr[i]].first = i;
			else 
				c[arr[i]].second = i;
		}
		make_tree(&v, 1, 1, n, arr);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (c[i].second == 0) continue;
			int d = query(&v, 1, 1, n, c[i].first, c[i].second);
			if (d > i) {
				cout << "No\n";
				flag = false;
				break;
			}
		}
		if (flag) cout << "Yes\n";
	}
}