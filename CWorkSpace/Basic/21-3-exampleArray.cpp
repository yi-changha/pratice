#include <stdio.h>

int main() {
	int n;
	int arr[100];

	scanf_s("%d", &n, 1);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i], 1);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			cnt++;
		}
	}

	printf("%d\n", cnt);
}