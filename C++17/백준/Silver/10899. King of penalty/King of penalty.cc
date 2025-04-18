#include <iostream>
#include<algorithm>
using namespace std;

int arr[100003];            

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p, n;
	cin >> p >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] < p) {
			sum += arr[i];
			cnt++;
		}
		else break;
	}

	int a = p - 1;
	long long res = 0;
	for (int i = 0; i < cnt; i++) {
		res += a;
		a -= arr[i];
	}
	cout << cnt << " " << res;
}
