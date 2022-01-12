#include <stdio.h>

int main() {
	char a;

	printf("문자입력 : ");
	scanf_s("%c", &a, 1);
	// scanf_s()를 사용해 입력받을 때는 ("%c", %a, 1)와 같이
	// 입력받을 글자 수를 추가적으로 적어줘야함

	printf("%c의 ASCII 값 : %d\n", a, a);

	int b;

	printf("숫자입력 : ");
	scanf_s("%d", &b, 1);
	printf("%d의 ASCII 값 : %c\n", b, b);
}