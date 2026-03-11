#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>v(N);
	stack<int>s;
	for (int i = 0;i < N;i++) {
		cin >> v[i];
	}
	s.push(v[N - 1]);
	v[N - 1] = -1;
	for (int i = N - 2;i >= 0;i--) {
		int a = v[i];
		while (!s.empty() && a >= s.top())
			s.pop();
		if (s.empty())
			v[i] = -1;
		else
			v[i] = s.top();
		s.push(a);
	}
	for (int a : v)
		cout << a << " ";
}