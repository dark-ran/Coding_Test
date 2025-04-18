#include<iostream>

using namespace std;

int arr[20000002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, i;
	cin >> n;
	while (n--) {
		cin >> i;
		arr[i+10000000]++;
	}
	cin >> n;
	while (n--) {
		cin >> i;
		cout << arr[i+10000000]<<" ";
	}
}