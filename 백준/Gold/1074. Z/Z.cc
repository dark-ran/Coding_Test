#include<iostream>

using namespace std;

int cnt = 0, n, r, c;
void func(int y, int x, int size) {
	if (y == r && x == c) {
		cout << cnt;
		return;
	}
	if (y <= r && r < y + size && x <= c && c < x + size) { //현재 사분면에 존재한다면
		func(y, x, size / 2); //1사분면
		func(y, x + size / 2, size / 2); //2사분면
		func(y + size / 2, x, size / 2); //3사분면
		func(y + size / 2, x + size / 2, size / 2); //4사분면
	}
	else {
		cnt += size * size;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> r >> c;
	func(0,0,(1<<n)); //(0,0,2의 n승)
}