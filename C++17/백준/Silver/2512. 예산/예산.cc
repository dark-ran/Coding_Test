#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v;

int main() {
	int n, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	scanf("%d", &temp);
	int low = 0;
	int high = v[v.size() - 1];
	while (low <= high) {
		int mid = (low + high) / 2;
		int tot = 0;
		for (int i : v) {
			if (i > mid) tot += mid;
			else tot += i;
		}
		if (tot <= temp) {
			n = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("%d", n);
}