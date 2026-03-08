#include<iostream>


using namespace std;

int arr[2188][2188];
int res[3];

void check(int x, int y, int size) {
	int num = arr[x][y];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[x + i][y + j] != num) { //만약 다른 값이 존재한다면 쪼개서 다시 확인
				for (int p = 0; p < 3; p++) {
					for (int k = 0; k < 3; k++) {
						check(x+p*size/3, y+k*size/3, size / 3);
					}
				}
				return;
			}
		}
	}
	res[num+1]++; //0번째에는 -1값, 1번째에는 0값, 2번째에는 1값
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	check(0, 0, n);
	cout << res[0] << "\n" << res[1] << "\n" << res[2];
}