#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int T, N, M, x;
	cin >> T >> N;

	vector<int>A(N);
	for (int i = 0;i < N;i++)
		cin >> A[i];
	cin >> M;
	vector<int>B(M);
	for (int i = 0;i < M;i++)
		cin >> B[i];

	vector<int>A_sum;
	for (int i = 0;i < N;i++) {
		int sum = A[i];
		A_sum.push_back(sum);
		for (int j = i + 1;j < N;j++) {
			sum += A[j];
			A_sum.push_back(sum);
		}
	}
	vector<int>B_sum;
	for (int i = 0;i < M;i++) {
		int sum = B[i];
		B_sum.push_back(sum);
		for (int j = i + 1;j < M;j++) {
			sum += B[j];
			B_sum.push_back(sum);
		}
	}
	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end());

	long long cnt = 0;
	auto b_begin = B_sum.begin();

	for (int i = A_sum.size() - 1; i >= 0; i--) {
		int a = A_sum[i];
		int target = T - a;

		auto lower = lower_bound(b_begin, B_sum.end(), target);
		auto upper = upper_bound(b_begin, B_sum.end(), target);

		cnt += (upper - lower);

		b_begin = lower;
	}
	cout << cnt << flush;
}