#include<iostream>
using namespace std;
int arr[1003]{ 0 };
void compare(int idx) {
	if (idx == 0) return;
	if (arr[idx - 1] > arr[idx]) {
		int temp = arr[idx - 1];
		arr[idx - 1] = arr[idx];
		arr[idx] = temp;
		compare(idx - 1);
	}
}
int main() {
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
		compare(i);
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
}