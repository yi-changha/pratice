//return : 돌려주다, 반환

#include <stdio.h>

// 2개의 매개변수(정수)의 합을 반환
int plus(int a, int b) {
	return a + b;
}

int main() {
	int sum = plus(3, 5);
	printf("%d\n", sum);
}