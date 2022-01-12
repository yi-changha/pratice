// char : 1바이트 정수형 (int: 4바이트)
// character : 문자 (반각문자 : ABCabc123_+;/#%) 
// 정각문자 : 한글, 한자, 일본어, ...

#include <stdio.h>

int main() {
	char a = 67;

	printf("%c\n", a);
	printf("%c\n", 'C'); // 'C'==67
}

// ASCII : American Standard (문자-숫자)