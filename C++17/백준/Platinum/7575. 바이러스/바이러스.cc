#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>fail(vector<int>& code) {
	vector<int>f(code.size());
	for (int i = 1, j = 0;i < code.size();i++) {
		while (j > 0 && code[i] != code[j])
			j = f[j - 1];
		if (code[i] == code[j])
			f[i] = ++j;
	}
	return f;
}

bool kmp(vector<int>& A, vector<int>&subpart) {
	vector<int>f = fail(subpart);
	for (int i = 0, j = 0;i < A.size();i++) {
		while (j > 0 && A[i] != subpart[j])
			j = f[j - 1];
		if (A[i] == subpart[j]) {
			if (j == subpart.size() - 1) return true;
			++j;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K, M;
	cin >> N >> K;
	vector<vector<int>>v(N);
	vector<vector<int>>f(N);
	for (int i = 0;i < N;i++) {
		cin >> M;
		v[i].resize(M);
		for (int j = 0;j < M;j++)
			cin >> v[i][j];
	}

	for (int i = 0;i < v[0].size() - K + 1;i++) {
		vector<int>code(K);
		for (int j = 0;j < K;j++)
			code[j] = v[0][i + j];

		bool check = true;
		for (int j = 1;j < N;j++) {
			vector<int>reverse_code = code;
			reverse(reverse_code.begin(), reverse_code.end());
			if (!kmp(v[j], code) && !kmp(v[j], reverse_code)) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}