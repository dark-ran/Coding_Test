#include<iostream>

using namespace std;

bool arr[102][102];

int main() {
	int a, b, c;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b;
		cin >> c;
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j < 10; j++) {
				arr[b + k][c + j] = true;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (arr[i][j])
				sum++;
		}
	}
	cout << sum;
}