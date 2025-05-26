#include<iostream>

using namespace std;

int arr[250001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (arr[i - 1] > arr[i]) {
			arr[i] <<= 1;
			cnt++;
		}
	}
	cout << cnt;
}