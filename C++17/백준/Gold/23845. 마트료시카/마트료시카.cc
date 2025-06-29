#include<iostream>
#define ll long long
using namespace std;
int cnt[100'001];
int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N,x;
	cin >> N;
	while (N--) {
		cin >> x;
		cnt[x]++;
	}
	ll sum = 0;
	for (int i = 100'000; i; i -= !cnt[i]) {
		for (int j = i; cnt[j]; j--) {
			cnt[j]--;
			sum += i;
		}
	}
	cout << sum << flush;
}