/* 4.
* 문자열을 매개변수로 받아 그 문자열에서 공백을
* 제거하여 출력하는 함수를 작성해보세요.
*/

#include <stdio.h>

void print_noSpace(const char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ')
			printf("%c", str[i]);
	}
}

int main() {
	print_noSpace("Hello, World!\n");
	print_noSpace("My name is Lee\n");
}


// 오류 해결방법
// 방법 1: 확장자를 .cpp에서 .c로 변경
// 방법 2: char를 const char로 변경해줌.
