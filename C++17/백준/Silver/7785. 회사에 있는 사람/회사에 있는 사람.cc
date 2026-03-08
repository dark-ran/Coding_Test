#include<iostream>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	map<string, int, greater<>>map1;
	for (int i = 0; i < n; i++) {
		string name, info;
		cin >> name >> info;
		if (info=="enter") 
			map1.insert(make_pair(name,0));
		else map1.erase(name);
	}

	for (auto i =map1.begin();i!=map1.end();i++)
		cout << i->first<<"\n";
}