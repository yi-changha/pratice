#include <stdio.h>

int main() {
	float a, b;
	
	// scanf() : �Է� �Լ�
	scanf_s("%f%f", &a, &b); //& : ������

	// �ֽŹ��� ���־�Ʃ������� scanf()�� ���Ȼ� �����ϴٰ� �Ǵ���.
	// ���1 : scanf_s() ���
	// ���2 : �� ���ٿ� #pragma warning(disable:4996) �Է�
	// ���3 : �� ���ٿ� #define_CRT_SECURE_NO_WARNINGS �Է�

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