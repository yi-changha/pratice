// �� ���ڸ� ��, ���� ������ ���� ���� �ִ����� �˾Ƴ�
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "sample";
	char str2[] = "simple";
	char str3[] = "simple";

	//int cmp = strcmp(str1, str2); // -1 : str1�� ���������� ���ʿ� �־
	//int cmp = strcmp(str2, str1); // 1
	int cmp = strcmp(str2, str3); // 0 : ���� ����

	printf("%d\n", cmp);
}