#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	string x;
	cin >> N;
	vector<pair<string, int>>arr;
	vector<string>origin;
	for (int i = 0;i < N;i++) {
		cin >> x;
		origin.push_back(x);
		arr.push_back({ x,i });
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	map<string, vector<int>>ma;
	int cnt = -1;
	for (int i = 0;i < arr.size() - 1;i++) {
		int j;
		string word;
		for (j = 0;j < arr[i].first.size() && j < arr[i + 1].first.size();j++) {
			if (arr[i].first[j] != arr[i + 1].first[j])
				break;
			word += arr[i].first[j];
		}
		if (cnt < j) { //접두사의 길이가 더 길 때
			ma.clear();
			cnt = j;
			ma[word].push_back(arr[i].second);
			ma[word].push_back(arr[i + 1].second);
		}
		else if (cnt == j) { //접두사의 길이가 같을 때
			ma[word].push_back(arr[i].second);
			ma[word].push_back(arr[i + 1].second);
		}
	}

	cnt = 20'001; //가장 앞에 있는 위치
	string S, T;
	for (auto a : ma) {
		sort(a.second.begin(), a.second.end());
		a.second.erase(unique(a.second.begin(), a.second.end()), a.second.end());
		if (a.second[0] < cnt) {
			cnt = a.second[0];
			S = origin[a.second[0]];
			T = origin[a.second[1]];
		}
	}
	cout << S << "\n" << T;
}