#include<iostream>
#include<cmath>

using namespace std;

string cantor(int n) {
	string str;
	str.resize(pow(3, n));
	str[0] = '-';
	for (int i = 1; i <= n; i++) {
		int leg = pow(3, i - 1);
		for (int j = 0; j < leg; j++) {
			str[leg + j] = ' '; //중간 열 공백처리
			str[leg * 2 + j] = str[j]; //오른쪽은 왼쪽과 똑같이
		}
	}
	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	while (cin >> n)
		cout<<cantor(n)<<"\n";
}