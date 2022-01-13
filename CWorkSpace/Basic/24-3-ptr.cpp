#include <stdio.h>

int main() {
	int a = 10;

	int *ptr;
	ptr = &a;

	printf("a의 값 : %d\n", a);

	*ptr = 20;
	// ptr이 가리키는 값에 20을 저장해라. a=20 (*ptr==a)
	// 즉, ptr 자체의 값은 바뀌지 않음.
	printf("a의 값 : %d\n", a);
}