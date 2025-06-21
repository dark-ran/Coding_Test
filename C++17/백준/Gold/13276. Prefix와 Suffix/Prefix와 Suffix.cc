#include<iostream>
#include<set>
#include<vector>

using namespace std;

int a[2001];
int b[2001];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string S, A, B;
	cin >> S >> A >> B;
	set<string>s;
	int A_size = A.size();
	int B_size = B.size();
	int S_size = S.size();

	int i = 1, j = 0;
	a[0] = 0;
	while (i < A_size) {
		while (A[i] != A[j] && j > 0) {
			j = a[j - 1];
		}

		if (A[i] == A[j]) {
			a[i++] = j++ + 1;
		}
		else {
			a[i++] = 0;
		}
	}
	i = 1, j = 0;
	b[0] = 0;
	while (i < B_size) {
		while (B[i] != B[j] && j > 0) {
			j = b[j - 1];
		}

		if (B[i] == B[j]) {
			b[i++] = j++ + 1;
		}
		else {
			b[i++] = 0;
		}
	}

	vector<int>A_start;
	vector<int>B_start;
	j = 0;
	for (i = 0; i < S_size; i++) {
		while (j > 0 && S[i] != A[j]) {
			j = a[j - 1];
		}
		if (S[i] == A[j]) {
			j++;
			if (j == A_size) {
				A_start.push_back(i - A_size + 1);
				j = a[j - 1];
			}
		}
	}
	j = 0;
	for (i = 0; i < S_size; i++) {
		while (j > 0 && S[i] != B[j]) {
			j = b[j - 1];
		}
		if (S[i] == B[j]) {
			j++;
			if (j == B_size) {
				B_start.push_back(i - B_size + 1);
				j = b[j - 1];
			}
		}
	}

	i = 0, j = 0;
	while(i<A_start.size()) {
		while (j < B_start.size()) {
			if (A_start[i] + A.size() <= B_start[j] + B.size() && A_start[i] <= B_start[j]) {
				string sub = S.substr(A_start[i], B_start[j] + B.size() - A_start[i]);
				s.insert(sub);
			}
			j++;
		}
		i++;
		j = 0;
	}
	
	cout << s.size() << flush;
}