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
	int s = 0, e = N - 1;
	ll res = 3'000'000'000;
	ll first, second;
	while (s < e) {
		if (abs(arr[s] + arr[e]) < res) {
			res = abs(arr[s] + arr[e]);
			first = arr[s], second = arr[e];
		}
		if (arr[s] + arr[e] > 0)
			e--;
		else if (arr[s] + arr[e] < 0)
			s++;
		else {
			cout << arr[s] << " " << arr[e];
			return 0;
		}
	}
	cout << first << " " << second;
}