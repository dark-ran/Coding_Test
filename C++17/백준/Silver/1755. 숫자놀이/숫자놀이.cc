#include<iostream>
#include<algorithm>

using namespace std;

string arr[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
bool com(int a,int b) {
	string t = a < 10 ? arr[a] : arr[a / 10] + arr[a % 10];
	string p = b < 10 ? arr[b] : arr[b / 10] + arr[b % 10];
	return t < p;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int* ans = new int[m - n + 1];
	for (int i = n; i <= m; i++) {
		ans[i - n] = i;	
	}
	sort(ans, ans + m - n + 1, com);

	for (int i = 0; i <= m-n; i++) {
		cout << ans[i]<<" ";
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	delete[]ans;
}