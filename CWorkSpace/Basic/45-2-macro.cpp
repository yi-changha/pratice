#include <stdio.h>

#define SQUARE(X) ((X) * (X))

int main() {
	int a;
	scanf_s("%d", &a, 1);
	printf("%d\n", SQUARE(a-1));
}