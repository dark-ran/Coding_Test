#include<iostream>
using namespace std;

bool arr[12][12]{ false };
string str[10];

int check(int a, int b) {
	int num = 0;
	for (int i = a - 1; i <= a + 1; i++) {
		for (int j = b - 1; j <= b + 1; j++){
			if (arr[i][j])
				num++;
		}
	}
	return num;
}
bool bomb(int n) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (str[i - 1][j - 1] == 'x') {
				if (arr[i][j])
					return false;
			}
		}
	}
	return true;
}

int main() {
	int n;
	bool bo = true;
	cin >> n;
	for (int i = 1; i < n+1; i++) {
		cin >> str[0];
		for (int j = 1; j < n+1; j++) {
			if (str[0][j-1] == '.')
				arr[i][j] = false;
			else
				arr[i][j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	bo = bomb(n);
	if (bo) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (str[i - 1][j - 1] == 'x') {
					cout << check(i, j);
				}
				else {
					cout << ".";
				}
			}
			cout << "\n";
		}
	}
	else {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (arr[i][j]) 
					cout << "*";
				else if (str[i - 1][j - 1] == 'x')
					cout << check(i, j);
				else 
					cout << ".";
			}
			cout << "\n";
		}
	}
}