#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		string s;
		cin >> s;
		vector<char>s1;
		vector<char>s2(N);
		for (int i = 0; i < N; i++) {
			if (s[i] == '1') {
				for (int j = i; j < N; j++) { //s1 = after first num one
					s1.push_back(s[j]);
				}
				break;
			}
		}
		int s1_size = s1.size();

		if (s1.size() == 0) { //all zero
			cout << "0\n";
			continue;
		}

		int prev_idx = 0;
		int zero_idx = 0;
		while (true) {
			for (int i = zero_idx; i < s1.size(); i++) { //find first zero
				if (s1[i] == '0') {
					zero_idx = i;
					break;
				}
			}

			if (zero_idx == prev_idx) {
				if (N == s1_size) { // "11" case
					s1[s1_size - 1] = '0';
				}
				for (int i = 0; i < s1_size; i++) {
					cout << s1[i];
				}
				cout << "\n";
				break;
			}
			else {
				prev_idx = zero_idx;
				string opt;
				for (int i = zero_idx; i < s1_size; i++) {
					opt += (s1[i] == '0' ? '1' : '0');
				}

				int max_idx = 1;
				int s2_size = s1_size - zero_idx;
				int range = N - s2_size;

				for (int i = 0; i < range; i++) { //find s2
					int idx = 0;
					for (int j = i; j < i + s1_size; j++) {
						if (s[j] == opt[j - i]) {
							idx = j - i + 1;
						}
						else if (idx > max_idx) {
							max_idx = idx;
							for (int k = 0; k < s2_size; k++) {
								s2[k] = s[i + k];
							}
							break;
						}
						else if (idx == max_idx) {
							int check = 0;
							int k;
							for (k = idx - 1; k < s2_size; k++) {
								if (s2[k] == opt[k] && s[i + k] != opt[k]) {
									check = 1;
									break;
								}
								else if (s2[k] != opt[k] && s[i + k] == opt[k]) {
									check = -1;
									break;
								}
							}
							if (check == -1) {
								for (; k < s2_size; k++) {
									s2[k] = s[i + k];
								}
							}
							break;
						}
						else {
							break;
						}
					}
				}

				//만약 첫번째 0으로부터 다 채우는 경우가 없을때
				if (opt[s2_size - 1] == '\0') {
					continue;
				}

				for (int i = 0; i < s1_size - s2_size; i++) { //print
					cout << s1[i];
				}
				for (int i = 0; i < s2_size; i++) {
					cout << (s1[i - s2_size + s1_size] ^ s2[i]);
				}
				cout << "\n";
				break;
			}
		}
	}
}