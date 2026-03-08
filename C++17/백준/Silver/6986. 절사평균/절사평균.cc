#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	double sum;
	cin >> n >> k;
	vector<double>a(n);
	for (auto& x : a)
		cin >> x;

	sort(a.begin(), a.end());
	sum = 0;
	for (int i = k; i < n - k; i++) {
		sum += a[i];
	}
	cout.precision(2);
	cout << fixed;
	cout << sum / (n - 2 * k) + 1e-13 << "\n";

	for (int i = 0; i < k; i++)
		sum += a[k] + a[n - k - 1];
	cout.precision(2);
	cout << fixed;
	cout << sum/n + 1e-13;
}