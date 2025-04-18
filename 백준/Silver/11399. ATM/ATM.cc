#include<stdio.h>
#include<algorithm>>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int sum = 0, tot = 0;
	for (int i = 0;i < n;i++) {
		sum += v[i];
		tot += sum;
	}
	printf("%d", tot);
}