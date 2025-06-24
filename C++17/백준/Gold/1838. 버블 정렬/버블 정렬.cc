#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, i;
	cin >> N;
	vector<int>arr(N);
	for (i = 0; i < N; i++)
		cin >> arr[i];

	vector<int>ans = arr;
	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int x = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
		cnt = cnt > i - x ? cnt : i - x;
	}
	cout << cnt;
}