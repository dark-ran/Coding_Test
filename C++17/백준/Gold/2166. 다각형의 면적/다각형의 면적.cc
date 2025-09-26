#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

long double solve(int i, int j) {
	long double a = v[0].first, b = v[0].second;
	long double c = v[i].first, d = v[i].second;
	long double e = v[j].first, f = v[j].second;

	return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	long double ans = 0;
	for (int i = 1; i < N - 1; i++) {
		ans += solve(i, i + 1);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans);
}