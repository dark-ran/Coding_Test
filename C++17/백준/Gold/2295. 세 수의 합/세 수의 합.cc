#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>arr(N);
	set<int>two;
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	for (int i = 0;i < N;i++) 
		for (int j = 0;j < N;j++)
			two.insert(arr[i] + arr[j]);
	
	for (int i = N - 1;i >= 0;i--) {
		for (int j = i - 1;j >= 0;j--) {
			if (two.find(arr[i] - arr[j]) != two.end()) {
				cout << arr[i];
				return 0;
			}
		}
	}
}