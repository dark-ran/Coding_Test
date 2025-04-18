#include<iostream>
#include<algorithm>
using namespace std;

pair <int, int> arr[100003];//<끝나는 시간, 시작 시간>
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, cnt = 0, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i].second >> arr[i].first;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i].second >= t) {
			cnt++;
			t = arr[i].first;
		}
	}
	cout << cnt;
}