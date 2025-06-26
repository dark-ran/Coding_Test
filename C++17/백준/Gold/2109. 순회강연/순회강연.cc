#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

bool vis[10'000];

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
	sort(arr.begin(), arr.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = arr[i].second - 1; j >= 0; j--) {
			if (!vis[j]) {
				vis[j] = true;
				sum += arr[i].first;
				break;
			}
		}
	}
	cout << sum;
}