#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "Hello";
	char str2[100];

	strcpy_s(str2, str1); 
	// strcpy : str2에 아무 값도 없었으나 str1의 값을 복사, 붙여넣기

	printf("str2의 값 : %s\n", str2);
}
