#include<stdio.h>

int main() {
	int a, b, cnt;
	scanf("%d%d", &a, &b);
	for (cnt = 1; a < b; cnt++) {
		if (b % 2 == 0)b /= 2;
		else if (b % 10 == 1) b /= 10;
		else break;
	}
	if (b != a) printf("-1");
	else printf("%d", cnt);
}