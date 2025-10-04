#include<iostream>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

int arr[1'000'005];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	long long N, B, C, n;
	long long cost = 0;
	cin >> N >> B >> C;
	if (B <= C) {
		for (int i = 0;i < N;i++) {
			cin >> n;
			cost += n * B;
		}
		cout << cost << flush;
		return 0;
	}
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	int D = B + 2 * C;
	C += B;
	for (int i = 0;i < N;i++) {
		if (arr[i + 1] > arr[i + 2]) {
			n = min(arr[i], arr[i + 1] - arr[i + 2]);
			arr[i] -= n;
			arr[i + 1] -= n;
			cost += n * C;
			n = min(arr[i], min(arr[i + 1], arr[i + 2]));
			arr[i] -= n;
			arr[i + 1] -= n;
			arr[i + 2] -= n;
			cost += n * D;
			cost += arr[i] * B;
		}
		else {
			n = min(arr[i], min(arr[i + 1], arr[i + 2]));
			arr[i] -= n;
			arr[i + 1] -= n;
			arr[i + 2] -= n;
			cost += n * D;
			n = min(arr[i], arr[i + 1]);
			arr[i] -= n;
			arr[i + 1] -= n;
			cost += n * C;
			cost += arr[i] * B;
		}
	}
	cout << cost;
}