#include<iostream>
#include<vector>

using namespace std;

vector<int>v;
vector<int>s;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	s.resize(N + 1, 0);
	for (int i = 0; i < N; i++) {
		int ma = v[i];
		int mi = v[i];
		for (int j = i; j >= 0; j--) {
			ma = ma > v[j] ? ma : v[j];
			mi = mi < v[j] ? mi : v[j];
			s[i + 1] = s[i + 1] > s[j] + ma - mi ? s[i + 1] : s[j] + ma - mi;
		}
	}
	cout << s[N];
}