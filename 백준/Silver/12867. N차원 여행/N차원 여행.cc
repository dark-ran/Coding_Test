#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

long long a[51];
long long b[51];

int main() {
	long long n, m;
	char c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + m);

	map<vector<int>, bool> ma;
	vector<int> mm(m, 0);
	ma[mm] = true;

	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == '+') {
			mm[lower_bound(b, b + m, a[i]) - b]++;
		}
		else {
			mm[lower_bound(b, b + m, a[i]) - b]--;
		}

		if (ma[mm]) {
			cout << "0";
			return 0;
		}
		ma[mm] = true;
	}
	cout << "1";
}