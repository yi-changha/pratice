/*
	1. ptr == &ptr[0]		//arr == &arr[0]
	2. *ptr == ptr[0]
	3. ptr + 1 == ptr 에 sizeof(*ptr)을 더한 값
*/

#include <stdio.h>
int main() {
	int arr[3] = { 1, 2, 3 };

	printf("arr = %d\n", arr);					//100으로 가정
	printf("sizeof() = %d\n", sizeof(arr[0]));	//4
	printf("arr + 1 = %d\n", arr+1);			//104

	printf("&arr = %d\n", &arr);				//100
	printf("sizeof(arr) = %d\n", sizeof(arr));	//12
	printf("&arr + 1 = %d\n", &arr + 1);		//112
	// &arr + sizeof(arr) == &arr + 1
	// &arr은 arr배열의 시작 주소를 나타냄.
}