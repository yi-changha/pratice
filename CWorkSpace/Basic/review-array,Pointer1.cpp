#include <stdio.h>

int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++) {
		printf("&arr[%d] = %d\n", i, &arr[i]);
		/* 출력값
		&arr[0] = 100으로 가정
		&arr[1] = 104
		&arr[2] = 108
		&arr[3] = 112
		&arr[4] = 116
		&arr[5] = 120
		&arr[6] = 124
		&arr[7] = 128
		&arr[8] = 132
		&arr[9] = 136
		*/
	}
	printf("\n");
	printf("arr = %d\n", arr);			//100 == &arr[0]
	// arr == &arr[0]; 둘이 같은 말.
	printf("&arr = %d\n", &arr);		//100 == &arr[0]
	printf("*arr = %d\n", *arr);		//1 == arr[0]
	printf("\n");

	printf("arr = %d\n", arr);			//100
	printf("arr+1 = %d\n", arr+1);		//104
	// arr + 1 == &arr[0] + 1
	// => arr + i == &arr[i]

	printf("\n*** arr+i == &arr[i] 증명 ***\n");
	for (int i = 0; i < 10; i++) {
		printf("arr + %d = %d\n", i, arr + i);
		printf("&arr[%d] = %d\n\n", i, &arr[i]);
	}
}