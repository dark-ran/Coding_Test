#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, ma = 0;
	string str;
	cin >> n;
	map<string,int>map1;
	while (n--) {
		cin >> str;
		map1[str]++;
	}
	for (auto i : map1) {
		ma = max(i.second, ma);
	}
	for (auto i : map1) {
		if (ma == i.second) {
			cout << i.first;
			return 0;
		}
	}
}