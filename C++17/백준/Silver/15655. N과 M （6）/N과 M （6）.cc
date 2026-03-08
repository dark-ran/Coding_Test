#include <iostream>

using namespace std;

int n, m;
int arr[10];
int lis[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (k == 0) {
			arr[k] = lis[i];
			func(k + 1);
		}
		else if (arr[k-1]<lis[i]) {
			arr[k] = lis[i];
			func(k + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	int a, b, k = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i == 0)
			lis[0] = a;
		for (k = 0; k < i; k++) {
			if (a < lis[k]) {
				b = lis[k];
				lis[k] = a;
				a = b;
			}
		}
		if (k == i)
			lis[i] = a;
	}
	func(0);
}