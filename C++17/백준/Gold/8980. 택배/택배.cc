#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct s {
	int start, end, num;
	bool operator<(const s& a) {
		if (end != a.end)
			return end < a.end;
		return start < a.start;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, C, M;
	cin >> N >> C >> M;
	vector<s>arr(M);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = { a,b,c };
	}
	sort(arr.begin(), arr.end());

	int res = 0;
	vector<int>pack(N, C);
	for (int i = 0; i < M; i++) {
		int MIN = arr[i].num;
		for (int j = arr[i].start; j < arr[i].end; j++) {
			MIN = MIN < pack[j] ? MIN : pack[j];
		}
		if (MIN == 0) continue;

		for (int j = arr[i].start; j < arr[i].end; j++) {
			pack[j] -= MIN;
		}
		res += MIN;
	}
	cout << res;
}