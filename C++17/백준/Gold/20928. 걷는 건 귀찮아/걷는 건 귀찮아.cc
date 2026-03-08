#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int>a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	vector<int>arr(1e6 + 1, 0);
	for (int i = 0; i < n; i++) arr[a[i]] = a[i] + b[i]; //최대 거리 저장
	for (int i = 1; i <= m; i++)
		arr[i] = arr[i] > arr[i - 1] ? arr[i] : arr[i - 1];

	int c = 0, des = a[0] + b[0];
	while (des < m and des < arr[des]) { //목적지에 도달하거나 이동할 곳이 없을때까지 
		c++;
		des = arr[des]; //최대 이동 위치로 이동
	}
	cout << (des >= m ? c : -1);
}