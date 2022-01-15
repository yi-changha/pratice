#include <stdio.h>

int main() {
	int arr[10] = { 3,1,4,1,5,9,2,6,5,3 };
	
	printf("%d\n", arr); // arr == &arr[0]의 주소값
	for (int i = 3; i < 7; i++) { // 4번째부터 8번째 전까지
		printf("%d %d\n", arr + i, *(arr + i)); // 주소값, 참조값
	}
}