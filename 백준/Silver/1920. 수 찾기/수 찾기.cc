#include<iostream>
#include<algorithm>
using namespace std;
int arr[100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, temp;
	cin >> n;
	for (int i = 0; i < n; i++)  cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	while (m--) {
		cin >> temp;
		cout << binary_search(arr, arr + n, temp) << "\n";
	}
}