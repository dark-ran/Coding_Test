#include<iostream>
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int arr[100'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	int res = -20'000'000;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
		if (i >= K)
			res = max(res, arr[i] - arr[i - K]);
	}

	cout << res;
}