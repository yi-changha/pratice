// call-by-value
// call-by-reference

#include <stdio.h>

void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main() {
	int a, b;

	scanf_s("%d%d", &a, &b, 2);

	swap(&a, &b);

	printf("a = %d, b = %d\n", a, b);
}