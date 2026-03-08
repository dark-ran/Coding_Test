#include<iostream>
#include<map>

using namespace std;

map<long long, long long>m;

long long f(long long i) {
	if (i < 2) return i;
	if (m.count(i)) return m[i];
	if (i % 2 == 0) {
		long long t1 = f(i / 2 - 1);
		long long t2 = f(i / 2);
		m[i] = ((2 * t1 + t2) * t2) % 1000000007;//오버플로우 방지
		return m[i];
	}
	long long t1 = f((i + 1) / 2);
	long long t2 = f((i - 1) / 2);
	m[i] = ((t1 * t1 + t2 * t2)) % 1000000007;//오버플로우 방지
	return m[i];
}

int main() {
	long long n;
	cin >> n;
	cout << f(n);
}