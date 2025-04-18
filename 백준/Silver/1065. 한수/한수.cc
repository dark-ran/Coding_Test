#include<stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		if (i < 100) {
			sum++;
			continue;
		}
		else if(i<1000){
			int first = i / 100;
			int second = (i % 100) / 10;
			int third = i % 10;
			if (first - second == second - third) sum++;
		}
	}
	printf("%d", sum);
}