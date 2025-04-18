#include<stdio.h>
#include<algorithm>>
#include<vector>

using namespace std;

long long sum(const vector<long long>&arr,long a,long long b) {
	long long z = 0;
	for (int i = a;i < b - 1;i++) {
		z += arr[i];
	}
	return z;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<long long,long long>>v(n);
	vector<long long>dis(n - 1);
	for (int i = 0;i < n - 1;i++) {
		scanf("%lld", &dis[i]);
	}
	for (int i = 0;i < n;i++) {
		long long a;
		scanf("%lld", &a);
		v[i] = { a,i };
	}
	sort(v.begin(), v.end());
	long long temp = v[0].second;
	long long tot = v[0].first * sum(dis, temp, n);
	temp++;
	for (int i = 1;i < n;i++) {
		if (v[i].second < temp) {//이전 비용보다 왼쪽에 있을 때
			tot += v[i].first * sum(dis, v[i].second, temp);
			temp = v[i].second + 1;
		}
	}
	printf("%lld", tot);
}