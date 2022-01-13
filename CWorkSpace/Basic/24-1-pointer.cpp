// 포인터(pointer) : 변수를 주소를 저장하는 변수
// ram의 상황이 달라지기 때문에 실행할 때마다 주소값은 달라짐

#include <stdio.h>

int main() {
	int a = 20;

	int *ptr_a; 
	// 가리키는 변수 형태(int) + * + 포인터 이름(ptr_a)

	ptr_a = &a;// &a : a의 주소값(&)

	printf("a의 값 : %d\n", a);
	printf("a의 주소값 : %d\n", &a);
	printf("ptr_a에 저장된 값 : %d\n", ptr_a);
	printf("ptr_a가 가리키는 변수의 값 : %d\n", *ptr_a); // *ptr_a==a
	// int *ptr_a 와 *ptr_a는 다름
	/* 
	a = 20
	주소는 실행시마다 바뀌지만 3275096
	ptr = 3275096
	*/
}
