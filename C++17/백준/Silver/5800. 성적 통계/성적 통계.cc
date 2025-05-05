#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int K, N;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> N;
		vector<int>v(N);
		int Max = 0;
		int Min = 100;
		int gap = 0;
		for (int j = 0; j < N; j++) {
			cin >> v[j];
			Max = Max > v[j] ? Max : v[j];
			Min = Min < v[j] ? Min : v[j];
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size() - 1; j++) {
			gap = gap > v[j + 1] - v[j] ? gap : v[j + 1] - v[j];
		}
		cout << "Class " << i << "\n";
		cout << "Max " << Max << ", Min " << Min << ", Largest gap " << gap << "\n";
	}
}