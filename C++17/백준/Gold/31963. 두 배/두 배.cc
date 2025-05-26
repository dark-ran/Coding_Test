#include<iostream>
#include<cmath>

using namespace std;

int arr[250001];
long long cnt_arr[250001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		double ratio = ceil(log(arr[i - 1] / (double)arr[i]) / log(2))+cnt_arr[i-1];
		if (ratio > 0) {
			cnt_arr[i] = (long long)ratio;
			tot += cnt_arr[i];
		}
	}
	cout << tot;
}