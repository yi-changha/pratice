// 연산자 : + - / * % += -= ++ -- && || !
// 조건문 : if() switch()
// 반복문 : while() for()

// 1. 시험 점수 입력
// 90 ~ 100 A
// 80 ~ 89 B
// 70 ~ 79 C
// 60 ~ 69 D
// 50 ~ 59 E

#include <stdio.h>

int main() {
	int i;
	printf("시험 점수를 입력하세요.\n");
	scanf_s("%d\n", &i, 1);

	if (100 < i) {
		printf("시험은 100점이 만점입니다.", i);
	}
	else if (90 <= i) {
		printf("%d, A", i);
	}
	else if (80 <= i) {
		printf("%d, B", i);
	}
	else if (70 <= i) {
		printf("%d,C", i);
	}
	else if (60 <= i) {
		printf("%d,D", i);
	}
	else if (50 <= i) {
		printf("%d, E", i);
	}
	else if (0 <= i) {
		printf("%d, 다음 기회를 노려보세요", i);
	}
	else {
		printf("입력 오류입니다.");
	}
}