#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct s {
	string nam;
	int kor, eng, math;
};
bool com(const s&a, const s&b) {
	if (a.kor != b.kor) return a.kor > b.kor;
	if (a.eng != b.eng) return a.eng < b.eng;
	if (a.math != b.math) return a.math > b.math;
	return a.nam < b.nam;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, b, c, d;
	string a;
	cin >> n;
	vector<s>v(n);
	for (int i=0;i < n;i++) {
		cin >> v[i].nam >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), com);
	for (int i=0;i<n;i++){
		cout << v[i].nam << "\n";
	}
}