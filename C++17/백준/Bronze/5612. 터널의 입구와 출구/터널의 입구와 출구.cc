#include <iostream>

using namespace std;
int main() {
	int n, m, i, s, a, b, max;
	cin >> n >> m;
	s = m;
	max = s;
	for (i=1; i <= n; i++) {
		cin >> a >> b;
		s += a - b;
		if (s < 0) {
			cout << "0";
			return 0;
		}
		if (max < s) max = s;
	}
	cout << max;
}
