#include<iostream>
#define MAX 1001

using namespace std;


int n;
int arr[MAX];
int dp[MAX];

int max(int x, int y) { return x > y ? x : y; }

void INPUT() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void SOL() {
	int anw = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j])
				dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
		}
		anw = anw > dp[i] ? anw : dp[i];
	}
	cout << anw;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	INPUT();
	SOL();
}