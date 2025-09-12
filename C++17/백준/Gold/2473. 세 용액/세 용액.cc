#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define abs(x) ((x)<0?-(x):(x))
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<ll>arr(N);
	for (int i = 0;i < N;i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	ll res = 9'876'543'210;
	ll first, second, third;

	for (int i = 0;i < N;i++) {
		int s = i + 1;
		int e = N - 1;
		while (s < e) {
			if (res > abs(arr[i] + arr[s] + arr[e])) {
				res = abs(arr[i] + arr[s] + arr[e]);
				first = arr[i];
				second = arr[s];
				third = arr[e];
			}
			if (arr[s] + arr[e] + arr[i] < 0) {
				s++;
			}
			else if (arr[s] + arr[e] + arr[i] > 0) {
				e--;
			}
			else {
				cout << arr[i] << " " << arr[s] << " " << arr[e];
				return 0;
			}
		}
	}
	cout << first << " " << second << " " << third;
}