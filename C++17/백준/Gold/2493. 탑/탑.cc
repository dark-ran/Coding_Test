#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, x;
	cin >> N >> x;
	stack<pair<int,int>>s;
	cout << "0";
	s.push({ x,1 });
	for (int i = 1;i < N;i++) {
		cin >> x;
		while (!s.empty() && s.top().first < x) 
			s.pop();
		if (s.empty()) {
			cout << " 0";
			s.push({ x,i + 1 });
			continue;
		}
		else {
			cout << " " << s.top().second;
			s.push({ x,i + 1 });
		}
	}
}