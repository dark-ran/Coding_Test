#include<iostream>
#include<vector>

using namespace std;

int v[20];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, x, sum = 0;
	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) {
			cin >> x;
			sum += x;
			v[i] += x;
			v[j] += x;
		}

	int l = 1 << N - 1;
	int res = 1987654321;
	for (int i = 1;i < l;i++) {
		int num = sum;
		for (int j = 0;j < N;j++) {
			if (i & (1 << j))
				num -= v[j];
		}
		res = res < abs(num) ? res : abs(num);
	}
	cout << res;
}