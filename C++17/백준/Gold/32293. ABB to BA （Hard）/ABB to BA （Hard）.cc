#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T, N;
	cin >> T;
	string s;
	while (T--) {
		cin >> N;
		string v;
		for (int i = 0; i < N; i++) {
			char a;
			cin >> a;
			v.push_back(a);
			while (v.size() > 2 && v[v.size() - 3] == 'A' && v[v.size() - 2] == 'B' && v[v.size() - 1] == 'B') {
				v.pop_back();
				v.pop_back();
				v.pop_back();
				v.push_back('B');
				s.push_back('A');
			}
			while (!s.empty()) {
				v.push_back(s.back());
				s.pop_back();
			}
		}
		cout << v << "\n";
	}
}