#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool checked[10];

void func(int k, int x) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = x; i <= n; i++) {
		if (!checked[i]) {
			arr[k] = i;
			checked[i] = true;
			func(k + 1, i);
			checked[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	func(0,1);
}