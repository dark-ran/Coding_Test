#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, cnt = 0; 
	cin >> n;
	for (int i = (n - 1) / 2; i > (n - 1) / 3; i--) {
		cnt += (3 * i - n) / 2 + 1;
	}
	cout << cnt;
}