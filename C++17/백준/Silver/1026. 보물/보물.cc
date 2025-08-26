#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
vector<int> b;


int main() {
	ios::sync_with_stdio(0);
	cout.tie(); cin.tie();
	int k;
	int num;
	int sum = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> k;
		a.push_back(k);
	}
	for (int i = 0; i < num; i++) {
		cin >> k;
		b.push_back(k);
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	for (int i = 0; i < num; i++) {
		sum += (a[i] * b[i]);
	}

	cout << sum << "\n";
	return 0;


}