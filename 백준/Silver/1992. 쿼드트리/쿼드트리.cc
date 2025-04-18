#include<iostream>
#include<vector>
using namespace std;

int n;
vector<string>arr;

string func(int x, int y, int size) {
	if (size == 1) return arr[x].substr(y, 1);
	string first=func(x, y, size / 2);
	string second = func(x, y + size / 2, size / 2);
	string third = func(x + size / 2, y, size / 2);
	string fourth = func(x + size / 2, y + size / 2, size / 2);

	if (first == second && second == third && third == fourth && fourth == first && first.length() == 1) return first;
	else return "(" + first + second + third + fourth + ")";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << func(0, 0, n);
}