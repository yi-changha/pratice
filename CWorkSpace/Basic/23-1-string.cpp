// 문자열 : 문자들이 열거

#include <stdio.h>

int main() {
	char s[100];
// char arr[] = "abc"; == char arr[] = {'a', 'b', 'c', '\0);
// \0 : 문자열의 끝을 나타냄

	scanf_s("%s", s, 101);

	printf("%s\n", s);
}