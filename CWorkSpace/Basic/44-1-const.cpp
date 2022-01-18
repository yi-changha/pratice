// 상수 : 변하지 않는 수
// 변수 : 변할 수 있는 수

#include <stdio.h>

int main() {
	const float PI = 3.141592;

	float a = PI;

	printf("π = %.2f\n", PI);
	printf("&PI = %d\n", &PI);	// 주소값 있음
}