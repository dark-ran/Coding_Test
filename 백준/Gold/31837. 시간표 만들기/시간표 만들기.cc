#include<iostream>
#include<vector>

using namespace std;

struct s {
	int num, week, start, end;
};
int res = 0;

void func(int day, int num, int N, vector<vector<s>>& v, vector<vector<pair<int,int>>>& vis) {
	if (num == 22) {
		res++;
		return;
	}
	if (day >= N || num > 22) return;
	for (auto a : v[day]) {
		bool flag = true;
		for (auto b : vis[a.week-1]) {
			if (!(a.end <= b.first || a.start >= b.second)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			vis[a.week-1].push_back({a.start,a.end});
			func(day + 1, num + a.num, N, v, vis);
			vis[a.week - 1].pop_back();
		}
	}
	func(day + 1, num, N, v, vis);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, A, C, D;
	string S, E;
	cin >> N;
	vector<vector<s>>v(N);
	for (int i = 0; i < N; i++) {
		cin >> A;
		for (int j = 0; j < A; j++) {
			cin >> C >> D >> S >> E;
			int s = S[0] * 10 * 60 + S[1] * 60 + S[3] * 10 + S[4];
			int e = E[0] * 10 * 60 + E[1] * 60 + E[3] * 10 + E[4];
			v[i].push_back({ C,D,s,e });
		}
	}
	vector<vector<pair<int, int>>>vis(7);
	func(0, 0, N, v, vis);
	cout << res;
}