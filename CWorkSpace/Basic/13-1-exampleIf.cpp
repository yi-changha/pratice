// 중첩 if문
// 중괄호 코딩 스타일

#include <stdio.h>

int main() {
	int a, b, c;

	scanf_s("%d%d%d", &a, &b, &c, 3);

// if, else 안에 문장이 한 줄만 있으면 {} 생략가능
	if (a > b) {
		if (a > c) printf("가장 큰 값은 %d\n", a);
		else printf("가장 큰 값은 %d\n", c);
	} else if (b > c) printf("가장 큰 값은 %d\n", b);
	else printf("가장 큰 값은 %d\n", c); // c > b
}