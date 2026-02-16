#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

vector<ll>arr;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	arr.resize(N);
	for(int i=0;i<N;i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());
	int sum = 0;
	for (int i = 0;i < N;i++) {
		int l = 0, r = N - 1;
		while (l < r) {
			if (l == i) {
				l++;
				continue;
			}
			if (r == i) {
				r--;
				continue;
			}
			ll x = arr[l] + arr[r];
			if (x < arr[i])
				l++;
			else if (x > arr[i])
				r--;
			else {
				sum++;
				break;
			}
		}
	}
	cout << sum;
}