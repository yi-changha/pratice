/*
3. ���ĺ��� �Է¹޾Ƽ� �� ���� ���ĺ��� ����ϴ� ���α׷��� ��������.
*/

#include<stdio.h>

int main()
{
	char a;

	printf("���ĺ� �Է� : (Z,z �Ұ�)");
	scanf_s("%c", &a, 1);
	char b = a + 1;
	printf("%c�� ���� ���ĺ��� %c�Դϴ�.",a, b);
}