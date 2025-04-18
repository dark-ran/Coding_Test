#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	long long temp;
	cin >> k >> n;
	vector<long long>v;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	long long low = 0;
	long long high = v[k - 1];
	temp = 0;
	while (low <= high) {
		long long mid = (low + high + 1) / 2;
		int tot = 0;
		for (int i : v) {
			tot += i / mid;
		}
		if (tot >= n) {
			temp = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << temp;

}