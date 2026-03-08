#include <stdio.h>

int main() {
	int n, x, i, j, a[10001];
	scanf("%d %d", &n, &x);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (j = 0; j < n; j++) {
		if (x > a[j])
			printf("%d ", a[j]);
	}
}