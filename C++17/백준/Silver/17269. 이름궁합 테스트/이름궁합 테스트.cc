#include <iostream>
#include <string>
using namespace std;
int arr3[999];

int main() {
	int i, n, m, a, b;
	cin >> n >> m;
	int k = 0;
	string arr1, arr2;
	int arr[27] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
	cin >> arr1 >> arr2;
	b = max(m, n);

	for (i = 0; i < b; i++) {
		if (i < n) {
			arr3[k] = arr[arr1[i]-'A'];
			k++;
		}
		if (i < m) {
			arr3[k] = arr[arr2[i]-'A'];
			k++;
		}
	}

	for (int j = n+m; j >2; j=j-1) {
		for (int i = 0; i < j-1; i++) {
			a = arr3[i] + arr3[i + 1];
			if (a > 9) { 
				a -= 10; 
			}
			arr3[i] = a;
		}
	}
	if(arr3[0] !=0)
		cout << arr3[0];
	cout << arr3[1] << "%";
}