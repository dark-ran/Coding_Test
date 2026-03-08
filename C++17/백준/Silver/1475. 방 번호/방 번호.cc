#include<iostream>

using namespace std;
int main() {
	string a;
	int max = 0;
	cin >> a;
	int arr[10] = { 0 };
	for (char c : a) {
		arr[c - '0']++;
	}

	int b = arr[6] + arr[9] + 1;
	arr[6] = b / 2;

	for (int i = 0; i < 9; i++) {
		max = max > arr[i] ? max : arr[i];
	}
	cout << max;
}