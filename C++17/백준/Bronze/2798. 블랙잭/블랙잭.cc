#include <iostream>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fio;
	int n, m, i, j, k, l, arr[105], a, b, c, max=0;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (j = 0; j < n; j++) {
		a = arr[j];
		for (k = j + 1; k < n; k++){
			b = arr[k];
			for (l = k + 1; l < n; l++) {
				c = arr[l];
				if (max < a + b + c && a+b+c<= m)
					max = a + b + c;
			}
		}
	}
	cout << max;
	return 0;
}
