#include<iostream>
#include<vector>

using namespace std;

int tree[26][2];

void PreTravel(int idx) {
	cout << (char)('A' + idx);
	if (tree[idx][0] != 0)
		PreTravel(tree[idx][0]);
	if (tree[idx][1] != 0)
		PreTravel(tree[idx][1]);
}

void MidTravel(int idx) {
	if (tree[idx][0] != 0)
		MidTravel(tree[idx][0]);
	cout << (char)('A' + idx);
	if (tree[idx][1] != 0)
		MidTravel(tree[idx][1]);
}

void PostTravel(int idx) {
	if (tree[idx][0] != 0)
		PostTravel(tree[idx][0]);
	if (tree[idx][1] != 0)
		PostTravel(tree[idx][1]);
	cout << (char)('A' + idx);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		char cur, left, right;
		cin >> cur >> left >> right;
		if (left != '.')
			tree[cur - 'A'][0] = left - 'A';
		if (right != '.')
			tree[cur - 'A'][1] = right - 'A';
	}

	PreTravel(0);
	cout << "\n";
	MidTravel(0);
	cout << "\n";
	PostTravel(0);
}