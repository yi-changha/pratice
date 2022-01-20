// 배열 포인터

#include <stdio.h>

int main() {
	int arr[3] = { 1, 2, 3 };

	int(*ptr_arr)[3]; // 길이 3인 int형 배열을 가리키는 포인터를 선언
	ptr_arr = &arr;

	printf("&arr = %d\n", &arr);				//100으로 가정
	printf("ptr_arr = %d\n", ptr_arr);			//100
	printf("\n");
	printf("&arr + 1 = %d\n", &arr + 1);		//112
	printf("ptr_arr + 1 = %d\n", ptr_arr +1);	//112
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", (*ptr_arr)[i]);			//1 2 3
	}
}