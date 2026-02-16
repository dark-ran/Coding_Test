#include<iostream>
#include<bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N, K, res = 0;
	bitset<32>b;
	cin >> N >> K;
	b = N;
	while(b.count() > K) {
		for (long long i = 1;;i <<= 1) {
			if (N & i) {
				res += i;
				N += i;
				b = N;
				break;
			}
		}
	}
	cout << res;
}