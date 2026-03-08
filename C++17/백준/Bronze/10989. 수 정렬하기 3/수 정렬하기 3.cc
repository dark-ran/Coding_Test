#include<iostream>

using namespace std;

int arr[10001]{ 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}
}