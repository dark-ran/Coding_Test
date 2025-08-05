#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>>jewel(N);
	vector<bool>vis(N);
	for (int i = 0;i < N;i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}

	vector<int>bag(K);
	for (int i = 0;i < K;i++) {
		cin >> bag[i];
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	priority_queue<int,vector<int>,less<int>>li;
	int idx = 0;
	while (idx < N) {
		if (jewel[idx].first <= bag[0]) {
			li.push(jewel[idx++].second);
		}
		else
			break;
	}

	ll res = 0;
	if (!li.empty()) {
		res = li.top();
		li.pop();
	}
	for (int i = 1;i < K;i++) {
		while (idx < N) {
			if (jewel[idx].first <= bag[i]) {
				li.push(jewel[idx++].second);
			}
			else
				break;
		}

		if (!li.empty()) {
			res += li.top();
			li.pop();
		}
	}
	cout << res << flush;
}