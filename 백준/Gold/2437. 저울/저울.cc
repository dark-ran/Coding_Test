#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int>v;

void INPUT() {
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void SOL() {
	sort(v.begin(), v.end());
	int res = 1;
	for (int i = 0; i < N; i++) {
		if (v[i] > res) {
			cout << res;
			return;
		}
		res += v[i];
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	INPUT();
	SOL();
}