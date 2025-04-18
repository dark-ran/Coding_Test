#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, a;
	long long res = 0;
	cin >> N;
	stack<int>s;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (s.empty()) {
			s.push(a);
			continue;
		}
		while (!s.empty() && s.top() <= a) {
			s.pop();
		}
		res += s.size();
		s.push(a);
	}
	cout << res;
}