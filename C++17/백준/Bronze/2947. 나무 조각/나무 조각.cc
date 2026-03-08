#include<iostream>

using namespace std;

int main() {
	int arr[5]{ 0 };
	int temp;
	bool check = true;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	here:
	for (int i = 0; i < 4; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			for (int k = 0; k < 5; k++) {
				cout << arr[k] << " ";
			}
			cout << "\n";
		}
	}
	for (int i = 0; i < 5; i++) {
		if (arr[i] != i + 1)
			goto here;
	}
}