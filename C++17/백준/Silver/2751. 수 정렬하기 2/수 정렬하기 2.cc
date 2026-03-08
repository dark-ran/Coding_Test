#include<iostream>
using namespace std;

int arr[1000001];
int temp[1000001];

void merge(int str, int end) {
	int mid = (str + end) / 2;
	int st = str;
	int en = mid;
	for (int i = str; i < end; i++) {
		if (en == end) temp[i] = arr[st++]; //en이 끝에 도달했을 때
		else if (st == mid)temp[i] = arr[en++]; //st가 끝에 도달했을 때
		else if (arr[st] < arr[en])temp[i] = arr[st++]; //왼쪽에 있는 값이 더 작을 때
		else temp[i] = arr[en++];//오른쪽에 있는 값이 더 작을 때
	}
	for (int i = str; i < end; i++) arr[i] = temp[i];
}

void merge_sort(int str, int end) {
	if (end - str == 1) return;
	int mid = (str + end) / 2;
	merge_sort(str, mid);
	merge_sort(mid, end);
	merge(str, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << "\n";
}