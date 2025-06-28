#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s;
	cin >> s;
	vector<int>A;
	vector<int>B;
	vector<int>C;
	A.resize(s.length());
	B.resize(s.length());
	C.resize(s.length());
	int asize = 0, bsize = 0, csize = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == 'A') {
			A[asize++] = i;
		}
		else if (s[i] == 'B') {
			B[bsize++] = i;
		}
		else if (s[i] == 'C') {
			C[csize++] = i;
		}
	}

	int a = 0, b = 0, c = 0, sum = 0;
	while (true) {
		if (a >= asize || b >= bsize)
			break;

		if (A[a] < B[b]) {
			sum++;
			a++;
			b++;
		}
		else {
			a++;
		}
	}

	while (true) { //남은 B와 C
		if (c >= csize || b >= bsize)
			break;

		if (B[b] < C[c]) {
			c++;
			b++;
			sum++;
		}
		else {
			b++;
		}
	}

	cout << sum;
}