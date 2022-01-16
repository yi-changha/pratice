#include <stdio.h>

int main() {
	int arr[3][3] = { 0 };

	//arr의 주소값을 100으로 가정하고 주석

	printf("%d\n", &arr); // 2차원 배열 전체를 가리키는 포인터 // 100
	printf("%d\n", arr); // 0번쨰 행 전체(1차원 배열)를 가리키는 포인터 // 100
	printf("%d\n", *arr); // 1차원 배열을 출력해라 // 100

	printf("%d\n", &arr[0]); // arr==&arr[0] 0번쨰 행 전체(1차원 배열)를 가리키는 포인터 // 100
	printf("%d\n", arr[0]); // 1차원 배열을 출력해라 // 100
	printf("%d\n", *arr[0]); // 0,0의 값 // 0

	printf("%d\n", &arr[0][0]); // 0,0의 주소값 // 100

	printf("%d\n", arr[0][0]); // 0,0의 값 // 0
}