#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int>positive;
	vector<int>negative;
	vector<int>zero;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x > 0) positive.push_back(x);
		else if (x < 0) negative.push_back(x);
		else zero.push_back(x);
	}

	sort(positive.begin(), positive.end(), greater<>());
	sort(negative.begin(), negative.end());

	int idx = 0;
	int sum = 0;
	int size = positive.size();
	while (idx < size) {
		if (idx < size - 1) {
			if (positive[idx + 1] == 1) {
				sum += positive[idx++];
				sum += 1 * (size - idx);
				break;
			}
			else {
				sum += positive[idx++] * positive[idx++];
			}
		}
		else {
			sum += positive[idx++];
			break;
		}
	}

	idx = 0;
	size = negative.size();
	while (idx < size) {
		if (idx < size - 1) {
			sum += negative[idx++] * negative[idx++];
		}
		else if (zero.empty()) {
			sum += negative[idx++];
			break;
		}
		else
			break;
	}

	cout << sum;
}