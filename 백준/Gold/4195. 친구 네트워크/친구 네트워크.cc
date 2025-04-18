#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string, int>m; //문자와 집합 사이즈
unordered_map<string, string>v;

string find(string x) {
	if (v[x] == x) return x;
	return v[x] = find(v[x]);
}

void Union(string x, string y) {
	string nx = find(x);
	string ny = find(y);
	if (nx == ny) return;
	v[ny] = nx;
	m[nx] += m[ny];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;
		m.clear();
		v.clear();
		int n = 0;
		while (F--) {
			string a, b;
			cin >> a >> b;
			if (m.count(a) == 0) {
				m.insert({ a,1 });
				v.insert({ a,a });
			}
			if (m.count(b) == 0) {
				m.insert({ b,1 });
				v.insert({ b,b });
			}
			Union(a, b);
			cout << m[find(a)] << "\n";
		}
	}
}