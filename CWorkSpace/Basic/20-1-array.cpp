#include <stdio.h>
int main() {
	int a[5];

	for (int i = 0; i <= 4; i++) {
		a[i] = i * 5;
		printf("%d\n", a[i]);
	}
}