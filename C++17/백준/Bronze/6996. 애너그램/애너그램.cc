#include<iostream>
using namespace std;
int find(string b, char c) {
	for (int k = 0; k < b.length(); k++) {
		if (b[k] == c)
			return k;
	}
	return -1;
}
bool func(string a, string b) {
	if (a.length() != b.length())
		return false;
	for (int i = 0; i < a.length();i++) {
		int idx = find(b, a[i]);
		if (idx == -1)
			return false;
		b[idx] = 0;
	}
	return true;
}

int main() {
	int n;
	string a, b;
	bool t;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		t = func(a, b);
		cout << a << " & " << b << " are ";
		if (t)
			cout << "anagrams.\n";
		else
			cout << "NOT anagrams.\n";
	}
}