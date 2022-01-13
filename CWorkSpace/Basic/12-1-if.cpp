#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n, 1);

	// n%2, n擊 2煎 釭換 釭該雖 : 0,1

	/*
	if (n % 2 == 0) {
		printf("n擎 礎熱\n");
	}
	else {
		printf("n擎 �汝酅n");
	}
	*/

	if (n % 2) {
		printf("n擎 �汝酅n");
	}
	else {
		printf("n擎 礎熱\n");
	}
}