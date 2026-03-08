#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, sum = 0;
	cin >> n;
	stack<int>s;
	while (n--) {
		cin >> a;
		if (a == 0)
			s.pop();
		else {
			s.push(a);
		}
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}