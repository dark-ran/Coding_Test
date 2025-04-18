#include<iostream>
#include<algorithm>

using namespace std;

int min_[3];
int max_[3];


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, a, b, c, x, y, z;
	cin >> N;
	cin >> min_[0] >> min_[1] >> min_[2];
	max_[0] = min_[0];
	max_[1] = min_[1];
	max_[2] = min_[2];
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		x = min_[0], y = min_[1], z = min_[2];
		min_[0] = a + min(x,y);
		min_[1] = b + min({ x,y,z });
		min_[2] = c + min(y,z);
		x = max_[0], y = max_[1], z = max_[2];
		max_[0] = a + max(x,y);
		max_[1] = b + max({ x,y,z });
		max_[2] = c + max(y,z);
	}
	cout << max({ max_[0], max_[1], max_[2] }) << " " << min({ min_[0], min_[1], min_[2] });
}