#include<iostream>
#include<stack>

using namespace std;

	int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int H, W, res = 0, a, ma;
	stack<int>s;
	cin >> H >> W;
	cin >> a;
	s.push(a);
	ma = a;
	for (int i = 1; i < W; i++){
		cin >> a;
		int cnt = 0;
		while (!s.empty() && s.top() < a) {
			res += min(ma,a) - s.top();
			s.pop();
			cnt++;
		}
		while (cnt--) s.push(a);
		s.push(a);
		ma = max(ma, a);
	}
	cout << res;
}