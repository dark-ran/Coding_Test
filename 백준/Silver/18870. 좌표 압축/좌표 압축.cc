#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<long long,int>>v;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end());
	long long temp = v[0].first;
	v[0].first = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first == temp) {
			v[i].first = v[i - 1].first;
			continue;
		}
		temp = v[i].first;
		v[i].first = v[i - 1].first + 1;
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {return a.second < b.second; });
	for (int i = 0; i < v.size(); i++) cout << v[i].first<<" ";
}