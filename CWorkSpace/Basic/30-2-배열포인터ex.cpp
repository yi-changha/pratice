#include <stdio.h>

int main() {
	int arr[3][3] = { 0 };

	printf("%d\n", &arr[0][0]); // 0,0의 주소값 100으로 가정

	printf("%d\n", arr[0] + 1); // 104
	printf("%d\n", &arr[0] + 1); // 112
	printf("%d\n", arr + 1); // 112
	printf("%d\n", &arr + 1); // 136

	// &arr[0][0] = arr[0] 미적분 개념으로 이해하면 편함!!
}