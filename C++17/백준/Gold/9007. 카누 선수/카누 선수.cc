#include<iostream>
#include<vector>
#include<algorithm>
#define abs(x) ((x)<0?-(x):(x))
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int T, K, N;
	cin >> T;
	while (T--) {
		cin >> K >> N;
		vector<int>A(N), B(N), C(N), D(N);
		for (int i = 0;i < N;i++) cin >> A[i];
		for (int i = 0;i < N;i++) cin >> B[i];
		for (int i = 0;i < N;i++) cin >> C[i];
		for (int i = 0;i < N;i++) cin >> D[i];
		vector<int>AB;
		vector<int>CD;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				AB.push_back(A[i] + B[j]);
				CD.push_back(C[i] + D[j]);
			}
		}

		sort(AB.begin(), AB.end());
		sort(CD.begin(), CD.end());
		int res = 19876654321;
		for (int i = 0;i < AB.size();i++) {
			int a = lower_bound(CD.begin(), CD.end(), K - AB[i]) - CD.begin();
			int b = a - 1;
			if (a == 0); //a가 맨 앞이면
			else if (a == AB.size()) //a가 맨 뒤면
				a = b;
			else if (abs(K - AB[i] - CD[a]) > abs(K - AB[i] - CD[b])) { //b가 더 가까울
				a = b;
			}
			else if (abs(K - AB[i] - CD[a]) == abs(K - AB[i] - CD[b]) && K > AB[i] + CD[b]) { //b가 더 작을
				a = b;
			}

			if (abs(K - res) > abs(K - AB[i] - CD[a]))
				res = AB[i] + CD[a];
			else if (abs(K - res) == abs(K - AB[i] - CD[a]) && K > AB[i] + CD[a])
				res = AB[i] + CD[a];
		}
		cout << res << "\n";
	}
}