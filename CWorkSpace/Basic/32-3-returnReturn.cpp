#include <stdio.h>

void noMeaning() {
	printf("first\n");
	return; //return을 만나면 즉시 함수 종료
	printf("second\n");
	return;
}

int main() {
	noMeaning();
}

// first
// return을 만나 즉시 종료되어 second 출력되지 않음