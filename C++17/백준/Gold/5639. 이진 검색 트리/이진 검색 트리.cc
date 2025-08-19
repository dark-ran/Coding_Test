#include<iostream>

using namespace std;

int arr[10'001];

void go(int s, int e) {
	if (s >= e) return;
	int par = arr[s];
	int m = s + 1;
	while (m < e) {
		if (par < arr[m]) break;
		m++;
	}
	go(s + 1, m);
	go(m, e);
	cout << par << "\n";
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int x, idx = 0;
	while (cin >> x) {
		arr[idx++] = x;
	}

	go(0, idx);
}