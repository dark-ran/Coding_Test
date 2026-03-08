#include<iostream>

using namespace std;

long long arr[86402];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		int x = ((s[0] - '0') * 10 + (s[1] - '0')) * 3600 + ((s[3] - '0') * 10 + (s[4] - '0')) * 60 + ((s[6] - '0') * 10 + (s[7] - '0'));
		cin >> s >> s;
		int y = ((s[0] - '0') * 10 + (s[1] - '0')) * 3600 + ((s[3] - '0') * 10 + (s[4] - '0')) * 60 + ((s[6] - '0') * 10 + (s[7] - '0'));
		arr[x]++;
		arr[y + 1]--;
		if (x > y) {
			arr[0]++;
			arr[86400]--;
		}
	}
	for (int i = 0; i < 86400; i++) arr[i + 1] += arr[i];
	for (int i = 0; i < 86400; i++) arr[i + 1] += arr[i];
	cin >> N;
	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < N; i++) {
		cin >> s;
		int x = ((s[0] - '0') * 10 + (s[1] - '0')) * 3600 + ((s[3] - '0') * 10 + (s[4] - '0')) * 60 + ((s[6] - '0') * 10 + (s[7] - '0'));
		cin >> s >> s;
		int y = ((s[0] - '0') * 10 + (s[1] - '0')) * 3600 + ((s[3] - '0') * 10 + (s[4] - '0')) * 60 + ((s[6] - '0') * 10 + (s[7] - '0'));
		if (x > y) cout << (double)(arr[86400] + arr[y] - arr[x - 1]) / (86401 - x + y) << "\n";
		else cout << (double)(arr[y] - arr[x - 1]) / (y + 1 - x) << "\n";
	}
}