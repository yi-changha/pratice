#include <stdio.h>

int main() {
	int a = 10;
	int *ptr_a = &a;
	//int *ptr_a
	//ptr_a = &a;
		
	printf("ptr_a의 값 : %d\n", ptr_a);				//100으로 가정
	printf("ptr_a + 1의 값 : %d\n", ptr_a + 1);		//104
	// ptr이 가리키고 있는 형 : int
	// int의 메모리 : 4B
	// ptr_a 와 ptr_a+1의 차이 : 4B
}