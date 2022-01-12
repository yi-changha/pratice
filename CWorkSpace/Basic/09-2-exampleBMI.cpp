/*
2. 체중과 키를 입력받아서 체질량 지수를 구하는 프로그램을 만들어보세요.
*/

#include<stdio.h>

int main()
{
	float a, b;
	printf("키(cm)를 입력하세요.");
	scanf_s("%f", &a, 1);
	printf("체중(kg)을 입력하세요.");
	scanf_s("%f", &b, 1);
	printf("당신의 체질량 지수는 %f%%입니다\n", b/(a*a/100/100));

}