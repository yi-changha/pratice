/*
3. 알파벳을 입력받아서 그 다음 알파벳을 출력하는 프로그램을 만들어보세요.
*/

#include<stdio.h>

int main()
{
	char a;

	printf("알파벳 입력 : (Z,z 불가)");
	scanf_s("%c", &a, 1);
	char b = a + 1;
	printf("%c의 다음 알파벳은 %c입니다.",a, b);
}