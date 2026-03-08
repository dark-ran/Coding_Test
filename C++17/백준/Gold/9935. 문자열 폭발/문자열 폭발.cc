#include<iostream>
#include <string.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b, c;
	bool check = true;
	c = "";
	int i;
	cin >> a >> b;
		for (i = 0; i < a.length(); i++) {
			c += a[i];
			if (c.length() >= b.length()) {
				for (int j = 0; j < b.length(); j++) {
					if (c[c.length() - b.length() + j] == b[j])
						check = true;
					else {
						check = false;
						break;
					}
				}
				if (check) {
					for (int k = 0; k < b.length(); k++) {
						c.pop_back();
					}
				}
			}
		}
		if (c.length() != 0)
			cout << c;
		else
			cout << "FRULA";
}