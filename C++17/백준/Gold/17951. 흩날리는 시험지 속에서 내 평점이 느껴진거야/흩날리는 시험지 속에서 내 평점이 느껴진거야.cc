#include<iostream>
#include<vector>

using namespace std;

vector<int>v;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K, res = 0;
	cin >> N >> K;
	v.resize(N);
	int start = 0, end = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		end += v[i];
	}
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 0, num = 0;
		for (int i = 0; i < N; i++) {
			num += v[i];
			if (num >= mid) {
				cnt++;
				num = 0;
			}
		}
		if (cnt < K) end = mid - 1;
		else {
			start = mid + 1;
			res = mid;
		}
	}
	cout << res;
}