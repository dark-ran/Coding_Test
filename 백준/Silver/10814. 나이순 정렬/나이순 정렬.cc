#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct s {
	int age, idx;
	string name;};
bool com(const s& a, const s& b) {
	if (a.age != b.age)return a.age < b.age;
	return a.idx < b.idx;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a;
	string b;
	cin >> n;
	vector<s>v;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		v.push_back({ a,i,b });
	}
	sort(v.begin(), v.end(), com);
	for (int i = 0;i < n;i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
}