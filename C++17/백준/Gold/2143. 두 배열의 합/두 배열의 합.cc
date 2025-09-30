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

	sort(B_sum.begin(), B_sum.end());
	long long cnt = 0;
	for (int a : A_sum) {
		int num = T - a;
		auto up = upper_bound(B_sum.begin(), B_sum.end(), num);
		auto end = lower_bound(B_sum.begin(), B_sum.end(), num);
		cnt += up - end;
	}
	cout << cnt;
}