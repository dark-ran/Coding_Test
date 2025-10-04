#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Tree {
public:
	Tree*child[26];
	bool isend;
	Tree() {
		isend = false;
		for (int i = 0;i < 26;i++)
			child[i] = nullptr;
	}
};

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int C, N, Q;
	string s;
	cin >> C >> N;
	Tree* tree = new Tree;
	for (int i = 0;i < C;i++) {
		Tree *cur = tree;
		cin >> s;
		for (int i = 0;i < s.size();i++) {
			if (cur->child[s[i] - 'a'] == nullptr)
				cur->child[s[i] - 'a'] = new Tree;
			cur = cur->child[s[i] - 'a'];
		}
		cur->isend = true;
	}

	unordered_set<string>se;
	for (int i = 0;i < N;i++) {
		cin >> s;
		se.insert(s);
	}

	cin >> Q;
	for (int i = 0;i < Q;i++) {
		cin >> s;
		Tree *cur = tree;
		bool flag = false;
		for (int i = 0;i < s.size();i++) {
			if (cur->child[s[i] - 'a'] == nullptr) {
				flag = false;
				break;
			}
			cur = (cur->child[s[i] - 'a']);
			if (cur->isend) {
				string a = s.substr(i + 1);
				if (se.find(a) != se.end()) {
					flag = true;
					break;
				}
			}
		}
		cout << (flag ? "Yes\n" : "No\n");
	}
}