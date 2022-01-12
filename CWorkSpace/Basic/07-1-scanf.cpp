#include <stdio.h>

int main() {
	float a, b;
	
	// scanf() : 입력 함수
	scanf_s("%f%f", &a, &b); //& : 포인터

	// 최신버전 비주얼스튜디오에서 scanf()가 보안상 위험하다고 판단함.
	// 방법1 : scanf_s() 사용
	// 방법2 : 맨 윗줄에 #pragma warning(disable:4996) 입력
	// 방법3 : 맨 윗줄에 #define_CRT_SECURE_NO_WARNINGS 입력

	/*
	float hap = a + b;
	float cha = a - b;
	float gop = a * b;
	float mok = a / b;
	*/

	printf("%f + %f = %f\n", a, b, a + b);
	printf("%f - %f = %f\n", a, b, a - b);
	printf("%f * %f = %f\n", a, b, a * b);
	printf("%f / %f = %f\n", a, b, a / b);

}