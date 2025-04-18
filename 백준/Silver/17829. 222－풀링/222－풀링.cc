#include<iostream>

using namespace std;

int arr[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, first, second;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = n; i > 1; i /= 2) {
		for (int j = 0; j < i; j += 2) {
			for (int k = 0; k < i; k += 2) {
				first = arr[j][k];
				if (first < arr[j][k + 1]) {
					second = first;
					first = arr[j][k + 1];
				}
				else {
					second = arr[j][k + 1];
				}
				if (first < arr[j + 1][k]) {
					second = first;
					first = arr[j + 1][k];
				}
				else if (second < arr[j + 1][k]) {
					second = arr[j + 1][k];
				}
				if (first < arr[j + 1][k + 1]) {
					second = first;
					first = arr[j + 1][k + 1];
				}
				else if (second < arr[j + 1][k + 1]) {
					second = arr[j + 1][k + 1];
				}
				arr[j / 2][k / 2] = second;
			}
		}
	}
	cout << arr[0][0];
}