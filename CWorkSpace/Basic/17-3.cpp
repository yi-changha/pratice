#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n, 1);
	
	int sum=0;
	for (int i = 1; i <= n; sum += i, i++);

	printf("%d\n", sum);
}