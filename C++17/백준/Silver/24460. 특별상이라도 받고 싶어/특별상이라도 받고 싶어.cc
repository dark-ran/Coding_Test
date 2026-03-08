#include<iostream>
#include<cmath>

using namespace std;

int arr[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, cnt, first, second;
	cin >> n;
	if (n == 1) {
		cin >> cnt;
		cout << cnt;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = n; i > 1;) {
		for (int j = 0; j < i;) {
			for (int k = 0; k < i;) {
				first = arr[j][k];
				if (first > arr[j][k+1]) {
					second = first;
					first = arr[j][k+1];
				}
				else
					second = arr[j][k+1];
				if (second > arr[j + 1][k]) {
					if (first > arr[j + 1][k]) {
						second = first;
						first = arr[j + 1][k];
					}
					else
						second = arr[j + 1][k];
				}
				if (second > arr[j + 1][k+1]) {
					if (first > arr[j + 1][k+1]) {
						second = first;
						first = arr[j + 1][k+1];
					}
					else
						second = arr[j + 1][k+1];
				}
				arr[j / 2][k / 2] = second;
				k += 2;
			}
			j += 2;
		}
		i /= 2;
	}
	cout << arr[0][0];
}