#include<iostream>
using namespace std;
int arr1[3]{ 0 };
int arr2[3]{ 0 };
int main() {
	int a;
	int temp,sum=0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (arr1[2] < a) {
			arr1[2] = a;
			if (arr1[1] < a) {
				temp = arr1[1];
				arr1[1] = a;
				arr1[2] = temp;
				if (arr1[0] < a) {
					temp = arr1[0];
					arr1[0] = a;
					arr1[1] = temp;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		sum += arr1[i];
	}
	cout << sum<<" ";
	sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (arr2[2] < a) {
			arr2[2] = a;
			if (arr2[1] < a) {
				temp = arr2[1];
				arr2[1] = a;
				arr2[2] = temp;
				if (arr2[0] < a) {
					temp = arr2[0];
					arr2[0] = a;
					arr2[1] = temp;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		sum += arr2[i];
	}
	cout << sum;
}