#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

int par[10'001];

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<pii>arr(N);
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		arr[i] = { p,d };
	}
	for (int i = 0; i <= 10'000; i++) {
		par[i] = i;
	}
	sort(arr.begin(), arr.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int slot = find(arr[i].second);
		if (slot != 0) {
			sum += arr[i].first;
			par[slot] = slot - 1;
		}
	}
	cout << sum;
}