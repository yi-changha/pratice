#include <stdio.h>

#define MAX(A,B) (((A) > (B)) ? (A) : (B))

int main() {
	int a = 5, b = 10;

	printf("%d\n", MAX(a, b));
}