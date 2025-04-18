#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, l, sum = 0;
	cin >> n >> m;
	vector<int>v{ 0 };
	for (int i = 0;i < n;i++) {
		cin >> k;
		sum += k;
		v.push_back(sum);
	}
	while (m--) {
		cin >> k >> l;
		cout << v[l] - v[k - 1] << "\n";
	}
}