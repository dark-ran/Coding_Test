#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N;
	int h = (int)ceil(log(N) / log(2));
	int size = 1 << h;
	vector<int>tree_0(size << 1), tree_1(size << 1);
	for (int i = 0;i < N;i++) {
		int x;
		cin >> x;
		if (x % 2) {
			tree_1[size + i]++;
		}
		else {
			tree_0[size + i]++;
		}
	}

	for (int i = size - 1;i > 0;i--) {
		tree_0[i] = tree_0[i << 1] + tree_0[i << 1 | 1];
		tree_1[i] = tree_1[i << 1] + tree_1[i << 1 | 1];
	}

	cin >> M;
	while(M--) {
		int q, l, r;
		cin >> q >> l >> r;
		if (q == 1) {
			if (tree_0[size + l - 1]) {//이전값이 짝수라면
				if (r % 2 == 0) {//다음값도 짝수라면
					continue;
				}
				else { //다음값이 홀수라면
					int idx = size + l - 1;
					while (idx) {
						tree_0[idx]--;
						tree_1[idx]++;
						idx >>= 1;
					}
				}
			}
			else { //이전값이 홀수라면
				if (r % 2 == 1) { //다음값도 홀수라면
					continue;
				}
				else {
					int idx = size + l - 1;
					while (idx) {
						tree_1[idx]--;
						tree_0[idx]++;
						idx >>= 1;
					}
				}
			}
		}
		else if (q == 2) {
			l += size - 1;
			r += size - 1;
			int res = 0;
			while (l <= r) {
				if (l & 1)res += tree_0[l++];
				if (~r & 1)res += tree_0[r--];
				l >>= 1, r >>= 1;
			}
			cout << res << "\n";
		}
		else if (q == 3) {
			l += size - 1;
			r += size - 1;
			int res = 0;
			while (l <= r) {
				if (l & 1)res += tree_1[l++];
				if (~r & 1)res += tree_1[r--];
				l >>= 1, r >>= 1;
			}
			cout << res << "\n";
		}
	}
}