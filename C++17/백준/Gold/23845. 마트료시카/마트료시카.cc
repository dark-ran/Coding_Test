#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int cnt[100'002];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	sort(arr.begin(), arr.end());
	ll res = 0;
	for (int i = 0; i < N; i++) {
		int x = arr[i];
		if (!cnt[x])
			continue;

		cnt[x]--;
		ll num = 1;
		for (int j = x + 1;; j++) {
			if (cnt[j]) {
				cnt[j]--;
				num++;
			}
			else {
				res += num * (j - 1);
				break;
			}
		}
	}
	cout << res << flush;
}