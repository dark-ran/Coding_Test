#include<iostream>
using namespace std;
int arr[5][5];
pair<int, int> num[26];

bool check() {
	int bingo = 0;
	int crossR = 0;
	int crossL = 0;
	for (int i = 0; i < 5; i++) {
		int row = 0;
		int col = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0)
				row++;
			if (arr[j][i] == 0)
				col++;
		}
		if (arr[i][i] == 0)
			crossL++;
		if (arr[4 - i][i] == 0)
			crossR++;
		if (row == 5)
			bingo++;
		if (col == 5)
			bingo++;
	}
	if (crossR == 5)
		bingo++;
	if (crossL == 5)
		bingo++;
	if (bingo > 2)
		return true;
	return false;
}

int main() {
	int a;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) { 
			cin >> arr[i][k];
			num[arr[i][k]] = { i,k };
		}
	}
	for (int i = 0; i < 25; i++) {
		cin >> a;
		arr[num[a].first][num[a].second] = 0;
		if (i > 10) {
			if (check()) {
				cout << i + 1;
				return 0;
			}
		}
	}
}