#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<int>mile;
	vector<int>arr;
	for (int i = 0;i < N;i++) {
		int p, l;
		cin >> p >> l;
		arr.resize(p, 0);
		for (int i = 0;i < p;i++)
			cin >> arr[i];
		if (p < l) {
			mile.push_back(1);
			continue;
		}
		else {
			sort(arr.begin(), arr.end(), greater<>());
			mile.push_back(arr[l - 1]);
		}
	}

	sort(mile.begin(), mile.end());
	int idx = 0;
	int res = 0;
	while (N>idx) {
		if (M >= mile[idx]) {
			M -= mile[idx++];
			res++;
		}
		else break;
	}
	cout << res << flush;
}