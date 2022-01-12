/*
1. 두 숫자를 입력받아서 그 숫자들의 합을 출력하는 프로그램을 만들어 보세요.
*/

#include<stdio.h>

int main()
{
	float a, b;
	scanf_s("%f%f", &a, &b, 1);
	printf("%f와 %f의 합은 %f입니다", a, b, a + b);

}
