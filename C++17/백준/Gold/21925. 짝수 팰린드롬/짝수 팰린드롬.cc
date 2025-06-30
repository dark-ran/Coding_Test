#include<iostream>

using namespace std;

int arr[5'001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	int s = 0;
	cin >> arr[0];
	int res = 0;
	bool flag;
	for (int i = 1; i < N; i++) {
		cin >> arr[i];
		if ((i - s) % 2 == 1) {
			flag = true;
			for (int j = (i - s) >> 1; j >= 0; j--) {
				if (arr[s + j] != arr[i - j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				s = i + 1;
				res++;
			}
		}
	}
	cout << (flag ? res : -1);
}