#include<iostream>
#include<bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int M, x;
	string s;
	cin >> M;
	bitset<21>a;
	while (M--) {
		cin >> s;
		if (s == "add")cin >> x, a |= (1 << x);
		else if (s == "remove")cin >> x, a[x] = 0;
		else if (s == "check") cin >> x, cout << a[x]<<"\n";
		else if (s == "toggle") cin >> x, a[x].flip();
		else if (s == "all") a.set();
		else if (s == "empty")a.reset();
	}
}
