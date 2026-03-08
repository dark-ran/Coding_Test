#include <iostream>

using namespace std;

int main() {
	int m;
	int a = 0;
	int b = 0;
	int i = 1;
	for (; i <= 10; i++) {
		cin >> m;
		b += m;
		if (abs(100 - a) < abs(100 - b));
		else {
			a = b;
		}
	}
	if (i == 10) cout << b;
	else cout << a;
}
