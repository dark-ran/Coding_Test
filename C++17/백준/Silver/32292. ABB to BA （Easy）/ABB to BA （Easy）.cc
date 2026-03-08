#include<iostream>
#include<vector>

using namespace std;

void check(vector<char>*a, int idx) {
	if (idx > 1) {
		if ((*a)[idx - 2] == 'A' && (*a)[idx - 1] == 'B' && (*a)[idx] == 'B') {
			(*a)[idx - 2] = 'B';
			(*a)[idx - 1] = 'A';
			(*a).erase((*a).begin() + idx);
			check(a, idx - 2);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<char>v;
		for (int i = 0; i < N; i++) {
			char a;
			cin >> a;
			v.push_back(a);
			check(&v, v.size()-1);
		}
		for (auto a : v)
			cout << a;
		cout << "\n";
	}
}