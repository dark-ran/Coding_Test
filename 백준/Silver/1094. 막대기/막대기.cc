#include<stdio.h>

using namespace std;

int main() {
	int x, a = 0;
	scanf("%d", &x);
	while (x) {
		if (x % 2 == 1) {
			a++;
			x >>= 1;
		}
		else {
			x >>= 1;
		}
	}
	printf("%d",a);
}