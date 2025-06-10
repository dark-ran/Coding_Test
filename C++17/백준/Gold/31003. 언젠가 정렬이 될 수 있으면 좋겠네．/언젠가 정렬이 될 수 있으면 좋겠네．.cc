#include<iostream>
#include<vector>

using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>v(N);
	for (int i = 0;i < N;i++) {
		cin >> v[i];
		int p = i;
		while (p > 0 && gcd(v[p-1], v[i]) == 1)p--;
		while (v[p] < v[i])p++;
		while (p < i)swap(v[p++], v[i]);
	}
	for (int a : v) {
		cout << a << " ";
	}
}