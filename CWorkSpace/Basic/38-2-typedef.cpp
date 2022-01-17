#include <stdio.h>

int main() {
	typedef const char *String;

	String name = "Lee";	// char *name = "Lee";

	printf("이름 : %s\n", name);
}

// 특별한 의미를 자료형에 부여할 때 쓰면 좋음.