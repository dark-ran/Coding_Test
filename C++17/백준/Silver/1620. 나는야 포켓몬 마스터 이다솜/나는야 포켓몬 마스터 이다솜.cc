#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

string arr[100'001];

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, M;
	cin >> N >> M;
	unordered_map<string, int>ma;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
		ma[arr[i]] = i;
	}

	string s;
	while (M--) {
		cin >> s;
		if (isdigit(s[0])) {
			int num = stoi(s);
			cout << arr[num] << "\n";
		}
		else {
			cout << ma[s] << "\n";
		}
	}
}