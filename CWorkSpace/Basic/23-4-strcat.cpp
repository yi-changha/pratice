#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = "Hello";
	strcat_s(str, "World!"); // strcat_s : ���ٿ��ִ� ����
	strcat_s(str, "World!");
	strcat_s(str, "World!");
	strcat_s(str, "World!");
	strcat_s(str, "World!");
	strcat_s(str, "World!");
	printf("%s\n", str);
}