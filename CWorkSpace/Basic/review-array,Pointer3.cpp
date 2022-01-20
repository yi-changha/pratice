//배열 포인터

#include <stdio.h>

int main() {
	int arr[3] = { 1,2,3 };
	int *ptr = arr;

	for (int i = 0; i < 3; i++) {
		printf("%d ", *(ptr + i));
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");

	// arr[i] == *(arr + i) == *(ptr + i) == *(i + ptr) == i[ptr]
	// *(ptr + i) == *(i + ptr) // 덧셈의 교환 법칙 이용; 오류 없음.

	// C언어 인식 방법
	// a[b] -> *(a + b) ; 바꿔서 인식해서 교환 법칙 가능.

	for (int i = 0; i < 3; i++) {
		printf("%d ", i[ptr]);
	}
	printf("\n");
}