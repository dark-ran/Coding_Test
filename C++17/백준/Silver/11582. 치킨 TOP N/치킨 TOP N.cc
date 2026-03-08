#include<iostream>
#include<algorithm>
using namespace std;

int arr[1048577];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, k;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	for (long long i = 1; i <= k; i++) {
		sort(arr + (i - 1) * (n / k), arr + i * (n / k));
	}
	for (long long i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}
}