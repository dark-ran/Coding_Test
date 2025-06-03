#include<stdio.h>
#define ll long long

using namespace std;

void swap(ll* a, ll* b) {
	ll t = *a;
	*a = *b;
	*b = t;
}

ll absl(ll x) {
	return x > 0 ? x : -x;
}

int main() {
	ll a, b, x, y, front, back;
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);

	if (y < 0 || y >= absl(x)) {
		printf("Unknwon Number");
		return 0;
	}

	if(a>b)
		swap(&a, &b);

	x = absl(x);

	ll k = (a / x - 1) * x;
	
	while (a > k + y) {
		k += x;
	}

	if (k + y > b) {
		printf("Unknwon Number");
		return 0;
	}
	else if (k + y + x <= b) {
		printf("Unknwon Number");
		return 0;
	}
	else
		printf("%lld", k + y);
}