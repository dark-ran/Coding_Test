#include<iostream>

using namespace std;

int func(int n,int r,int c) {
	if (n == 0) return 0;
	int b = 1 << n - 1;
	//(b,b)의 위치는 좌표판 정 가운데
	if (r < b && c < b)  //1사분면에 존재한다면
		return func(n - 1, r, c);
	else if (r < b && c >= b) //2사분면에 존재한다면
		return func(n - 1, r, c - b) + b * b;
	else if (r >= b && c < b) //3사
		return func(n - 1, r - b, c) + 2 * b * b;
	else //4사	
		return func(n - 1, r - b, c - b) + 3 * b * b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, r, c;
	cin >> n >> r >> c;
	cout << func(n, r, c);
}