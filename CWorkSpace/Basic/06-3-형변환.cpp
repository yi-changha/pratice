// 형변환 : 자료형을 다른 자료형으로 바꾸는 작업

#include <stdio.h>

int main() {
	int math = 90, korean = 95, english = 96;
	int sum = math + korean + english;
	double avg = (double)sum / 3;
				// (double) 잠시동안 실수가 됨 => 실수가 나오게 됨

	printf("%f\n", avg); // 구해야할 값은 93.666667
}

// 정수 / 정수 = 정수
// 실수 / 정수 = 실수
// 실수 / 실수 = 실수

// 정수 + 정수 = 정수
// 정수 + 실수 = 실수
// 실수 + 실수 = 실수