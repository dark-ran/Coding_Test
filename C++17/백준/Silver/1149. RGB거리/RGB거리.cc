#include<iostream>

using namespace std;

int arr[3][1003];
int cost[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cin >> arr[0][0] >> arr[1][0] >> arr[2][0];
	for (int i = 1; i < n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[0][i] = min(arr[1][i-1], arr[2][i-1]) + cost[0]; //R
		arr[1][i] = min(arr[0][i-1], arr[2][i-1]) + cost[1]; //G
		arr[2][i] = min(arr[0][i-1], arr[1][i-1]) + cost[2]; //B
	}
	cout << min(min(arr[0][n - 1], arr[1][n - 1]), arr[2][n - 1]);
}