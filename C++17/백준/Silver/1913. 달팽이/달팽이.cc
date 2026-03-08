#include <iostream>
using namespace std;
int arr[1000][1000];
int main() {
		int n, m;
		int a = 1;
		int b = -1;
		int c = 0;
		int q, w;
		cin >> n >> m;
		int p = n * n;
		for (int i = (n+1) * 2; i > 2;i--) {
			for (int k = (i / 2) - 1; k > 0; k--) {
				if (a % 4 == 1) {
					b++;
					arr[b][c] = p;
					p--;
				}
				else if (a % 4 == 2) {
					c++;
					arr[b][c] = p;
					p--;
				}
				else if (a % 4 == 3) {
					b--;
					arr[b][c] = p;
					p--;
				}
				else {
					c--;
					arr[b][c] = p;
					p--;
				}
			}
			a++;
		}
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				cout << arr[i][k];
				if (arr[i][k] == m) {
					q = i; 
					w = k;
			}
				cout << " ";
			}
			cout << "\n";
		}
		cout << q + 1 << " " << w + 1;
}