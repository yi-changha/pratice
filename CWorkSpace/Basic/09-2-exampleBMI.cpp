/*
2. ü�߰� Ű�� �Է¹޾Ƽ� ü���� ������ ���ϴ� ���α׷��� ��������.
*/

#include<stdio.h>

int main()
{
	float a, b;
	printf("Ű(cm)�� �Է��ϼ���.");
	scanf_s("%f", &a, 1);
	printf("ü��(kg)�� �Է��ϼ���.");
	scanf_s("%f", &b, 1);
	printf("����� ü���� ������ %f%%�Դϴ�\n", b/(a*a/100/100));

}