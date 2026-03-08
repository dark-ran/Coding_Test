#include<iostream>


using namespace std;
int a[1000001]{ 0 };
int b[1000001]{ 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	int a_in = 0, b_in = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	while (a_in < n && b_in < m) {
		if (a[a_in] < b[b_in])
			cout << a[a_in++] << " ";
		else
			cout << b[b_in++] << " ";
	}
	while (a_in < n)
		cout << a[a_in++] << " ";
	while (b_in < m)
		cout << b[b_in++] << " ";
}