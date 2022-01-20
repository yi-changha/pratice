/*
	1. arr == &arr[0]		ptr == &ptr[0]
	2. *arr == arr[0]
	3. ptr + 1 == ptr 에 sizeof(*ptr)을 더한 값
*/


#include <stdio.h>

int main() {
	int arr[2][3] = { { 1, 2, 3}, {4, 5, 6} };

	printf("%d\n", sizeof(arr));		//24B	sizeof(int) * 2 * 3 = 24B
	printf("%d\n", sizeof(arr[0]));		//12B	sizeof(int) * 3 = 12B
	printf("%d\n", sizeof(arr[0][0]));	//4B	sizeof(int) = 4B
	printf("\n");

	printf("%d\n", &arr);		//100으로 가정	array가 처음 시작하는 주소
	printf("%d\n", &arr[0]);	//100			0번째 행이 처음 시작하는 주소
	printf("%d\n", &arr[0][0]);	//100			0,0의 주소
	printf("\n");


	// 2차원 배열을 포인터로 치환하는 방법
	// 2차원 배열의 한 행을 가리킬 수 있는 배열 포인터를 만들고,
	// 배열포인터에 array를 집어넣는다.


	int(*ptr)[3] = arr;		// 3개를 갖는 1차원 배열

	// 1. ptr[i] == arr[i]
	// 2. ptr[i][j] == arr[i][j]
	// => ptr == arr

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}