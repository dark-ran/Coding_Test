#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
using namespace std;

pii arr[100'000];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N);
	for (int i = 0;i < N;i++)
		cout << arr[i].first << " " << arr[i].second << "\n";
}