#include<iostream>
#include<vector>
#include<queue>
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
	
	map<string, priority_queue<int,vector<int>,greater<int>>>ma;
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
			ma[word].push(arr[i].second);
			ma[word].push(arr[i + 1].second);
		}
		else if (cnt == j) { //접두사의 길이가 같을 때
			ma[word].push(arr[i].second);
			ma[word].push(arr[i + 1].second);
		}
	}

	cnt = 20'001; //가장 앞에 있는 위치
	string S, T;
	for (auto a : ma) {
		if (a.second.top() < cnt) {
			cnt = a.second.top();
			S = origin[a.second.top()];
			while (a.second.top() == cnt) a.second.pop();
			T = origin[a.second.top()];
		}
	}
	cout << S << "\n" << T;
}