#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int ma = 1, sum = 1,idx = v[0];
	for (int i = 1;i < n;i++) {
		if (idx == v[i]) sum++;
		else {
			ma = ma > sum ? ma : sum;
			sum = 1;
			idx = v[i];
		}
	}
	ma = ma > sum ? ma : sum;
	printf("%d", ma);
}