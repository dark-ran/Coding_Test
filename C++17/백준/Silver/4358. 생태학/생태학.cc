#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;
unordered_map<string, int>ma;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char str[30];
	float tot = 0;
	while (cin.getline(str, 100)) {
		tot++;
		ma[str]++;
	}
	cout << fixed;
	cout.precision(4);
	vector<pair<string, int>>v(ma.begin(), ma.end());
	sort(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end();i++) {
		cout << i->first << " " << i->second * 100 / tot<< "\n";
	}
}