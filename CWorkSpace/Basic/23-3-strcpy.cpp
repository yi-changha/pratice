#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Hello";
	char str2[100];

	strcpy_s(str2, str1); 
	// strcpy : str2�� �ƹ� ���� �������� str1�� ���� ����, �ٿ��ֱ�

	printf("str2�� �� : %s\n", str2);
}
