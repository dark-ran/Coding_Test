#include<iostream>

using namespace std;

bool board[51][51];

int check(int x, int y) {
	int lef = 0, rig = 0;
	for (int i = 0; i < 8; i++) { //시작이 'W'인 경우
		for (int j = 0; j < 8; j++) {
			if (((x + i) % 2 + (y + j) % 2) % 2 == 0) { //'B'인 경우
				if (!board[x + i][y + j])
					lef++;
			}
			else { //'W'인 경우
				if (board[x + i][y + j])
					lef++;
			}
		}
	}
	for (int i = 0; i < 8; i++) { //시작이 'B'인 경우
		for (int j = 0; j < 8; j++) {
			if (((x+i) % 2 + (y+j) % 2) % 2 == 1) { //'W'인 경우
				if (!board[x + i][y + j])
					rig++;
			}
			else { //'B'인 경우
				if (board[x + i][y + j])
					rig++;
			}
		}
	}
	return lef < rig ? lef : rig ; //lef와 rig 중에 좀 더 작은 값으로 반환
}

int main(){
	int n, m, sum = 2500, cur;
	string arr;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		for (int j = 0; j < m; j++) {
			if (arr[j] == 'W') //'W'이면 참, 'B'이면 거짓으로 보드 설정
				board[i][j] = true;
			else
				board[i][j] = false;
		}
	}
	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			cur = check(i, j);
			sum = sum < cur ? sum : cur; //sum과 cur 중에 좀 더 작은 값으로 sum 설정
		}
	}
	cout << sum;
}