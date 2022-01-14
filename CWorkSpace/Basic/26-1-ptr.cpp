#include <stdio.h>

int main() {
	int arr[3] = { 1, 2, 3 };
	int *ptr = arr;

	for (int i = 0; i < 3; i++) {
		printf("%d ", *(ptr + i)); // 1 2 3
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", ptr[i]); // 1 2 3
	// arr[i]와 같이 ptr[i]사용 가능
	}
	printf("\n");

	// a[b] -> *(a + b)
	// arr[i] == *(arr+i) == *(ptr+i) == *(i + ptr) = i[ptr]
	for (int i = 0; i < 3; i++) {
		printf("%d ", i[ptr]); // 1 2 3
	}
	printf("\n");
}