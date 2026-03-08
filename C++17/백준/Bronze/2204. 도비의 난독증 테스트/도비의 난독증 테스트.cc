#include<iostream>

using namespace std;

string arr[10003];
int main() {
	int n;
	string a, b, c, ans;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> a;
			c = a;
			for (int k = 0; k < a.length(); k++) {
				if (a[k] < 'a')
					a[k] = a[k] - 'A' + 'a';
			}
			if (i == 0) {
				b = a;
				ans = c;
			}
			else {
				if (a < b) {
					b = a;
					ans = c;
				}
			}
		}
		cout << ans << "\n";
	}
}