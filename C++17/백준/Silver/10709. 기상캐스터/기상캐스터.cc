#include<iostream>
using namespace std;
int h, w;
string arr[100];
int sol[100][100];

void check() {
	for (int i = 0; i < h; i++) {
		int k = 101;
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'c') {
				k = j;
				sol[i][j] = 0;
			}
			else {
				if (k == 101)
					sol[i][j] = -1;
				else
					sol[i][j] = j - k;
			}
		}
	}
}

int main() {
	string a;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		int j = 0;
		cin >> arr[i];
	}
	check();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cout << sol[i][j] << " ";
		cout << "\n";
	}
}