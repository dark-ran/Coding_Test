#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m, max = 0;
	cin >> n >> m;
	for (long long i = 0; i < n; i++)  cin >> arr[i];
	sort(arr, arr + n);
	long long front = 0;
	long long end = arr[n - 1];
	long long mid;
	while (front<=end) {
		mid = (front + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)sum += arr[i] - mid;
		}
		if (sum >= m) {
			front = mid + 1;
			max = mid;
		}
		else
			end = mid - 1;
	}
	cout << max;
}