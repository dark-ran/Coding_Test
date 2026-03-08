#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main() {
	string s;
	stack<int>index;
	vector<pair<int,int>>pa;
	vector<string>res;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '(')
			index.push(i);
		else if (s[i] == ')') {
			pa.push_back({ index.top(),i });
			index.pop();
		}
	}

	sort(pa.begin(), pa.end());
	int p = pa.size();
	for (int mask = 1;mask < (1 << p);mask++) {
		vector<bool>remove(s.size(), false);
		for (int j = 0; j < p; j++) {
			if (mask & (1 << j)) {
				remove[pa[j].first] = true;
				remove[pa[j].second] = true;
			}
		}

		string temp = "";

		for (int i = 0; i < s.size(); i++) {
			if (!remove[i])
				temp += s[i];
		}

		res.push_back(temp);
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	for (auto& x : res)
		cout << x << "\n";
}