#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>dp(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	//문제 해결
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}

	//결과 출력
	cout << dp[n - 1] << '\n';
}