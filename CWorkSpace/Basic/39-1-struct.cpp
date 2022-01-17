// 구조체 : 여러 개의 변수를 하나의 이름으로 묶고 사용하는 방법

#include <stdio.h>

struct Point { int x, y; };
// typedef struct { int x, y} Point;

int main() {
	Point p;

	p.x = 3;
	p.y = 4;

	printf("(%d, %d)\n", p.x, p.y);
	printf("sizeof(p) = %d\n", sizeof(p));
}