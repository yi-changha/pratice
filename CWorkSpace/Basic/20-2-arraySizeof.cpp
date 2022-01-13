#include <stdio.h>

int main() {
	// array
	int arr[] = {3, 1, 4, 1, 5, 6, 8, 3, 1, 4, 6};

	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}