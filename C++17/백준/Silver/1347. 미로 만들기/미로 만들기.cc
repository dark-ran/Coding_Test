#include<iostream>
using namespace std;
string maze[253][253];
int main() {
	int p, a = 100, b = 100, c = 100, d = 100;
	int x = 100, y = 100;
	int di = 2;
	string arr;
	cin >> p >> arr;
	maze[x][y] = ".";
	for (char z : arr) {
		if (z == 'R') {
			di = (di + 1) % 4;
		}
		else if (z == 'L') {
			di = (di + 3) % 4;
		}
		else {
			if (di == 0) {
				y--;
				maze[x][y] = ".";
				if (y < a) {
					a = y;
				}
			}
			else if (di == 1) {
				x++;
				maze[x][y] = ".";
				if (x > b) {
					b = x;
				}
			}
			else if (di == 2) {
				y++;
				maze[x][y] = ".";
				if (y > c) {
					c = y;
				}
			}
			else if (di == 3) {
				x--;
				maze[x][y] = ".";
				if (x < d) {
					d = x;
				}
			}
		}
	}
	string res;
	for (int j = a; j <= c; j++) {
		for (int i = d; i <= b; i++) {
			res=maze[i][j];
			if (res == ".")
				cout << res;
			else
				cout << "#";
		}
		cout << "\n";
	}
}