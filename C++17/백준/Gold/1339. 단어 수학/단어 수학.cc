#include<iostream>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

int pos[26];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int pow = 1;
		for (int i = s.size() - 1;i >= 0;i--) {
			pos[s[i] - 'A'] += pow;
			pow *= 10;
		}
	}
	
	int num = 9;
	int res = 0;
	sort(pos, pos + 26, greater<>());
	for (int i = 0;i < 10;i++) {
		res += (pos[i] * num--);
	}
	cout << res;
}