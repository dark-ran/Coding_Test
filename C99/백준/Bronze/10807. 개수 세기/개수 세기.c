#include <stdio.h>

int main() {
	int n;
	int a[101];
	int v;
	int count=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &v);
	for (int b = 0; b < n; b++) {
		if (v == a[b]) {
			count++;
		}
	}
	printf("%d",count);
	return 0;
}
