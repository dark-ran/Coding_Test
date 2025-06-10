#include<stdio.h>
#include<vector>
#include<queue>
#define pii pair<int,int>

using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int>v(N);
	vector<vector<int>>a(N);
	vector<int>num(N);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0;i < N;i++) {
		scanf("%d", &v[i]);
	}
	for (int i = 1;i < N;i++) {
		for (int j = i - 1;j >= 0;j--) {
			if (gcd(v[i], v[j]) != 1) {
				a[j].push_back(i);
				num[i]++;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		if (num[i] == 0)pq.push({ v[i],i });
	}
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		printf("%d ", cur.first);
		for (auto a : a[cur.second]) {
			num[a]--;
			if (num[a] == 0)
				pq.push({ v[a],a });
		}
	}
}