#include <stdio.h>

int main() {
	int arr[4] = { 1, 2, 3, 4 };
	int *ptr[4];

	for (int i = 0; i < 4; i++) {
		ptr[i] = &arr[i]; // ptr배열에 arr 각 변수의 주소값 대입
	}

	for (int i = 0; i < 4; i++) {
		printf("%d ", *ptr[i]); // 1 2 3 4
	}
	printf("\n"); 
}