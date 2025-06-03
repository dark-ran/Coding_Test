#include<stdio.h>
#define ll long long
#define absl(x) ((x)>0?(x):-(x))
void s(ll*a, ll*b) { ll t = *a; *a = *b; *b = t; }
int main() {
	ll a, b, x, y, k;
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	if (y < 0 || y >= absl(x)) { printf("Unknwon Number"); return 0; }
	if (a > b)s(&a, &b);
	x = absl(x);
	k = (a / x - 1) * x;
	while (a > k + y)k += x;
	if (k + y > b || k + y + x <= b)printf("Unknwon Number");
	else printf("%lld", k + y);
}