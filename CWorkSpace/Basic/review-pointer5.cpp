#include <stdio.h>

int main() {
	int a = 10;
	int *ptr_a = &a;
	//int *ptr_a
	//ptr_a = &a;
		
	printf("ptr_a�� �� : %d\n", ptr_a);				//100���� ����
	printf("ptr_a + 1�� �� : %d\n", ptr_a + 1);		//104
	// ptr�� ����Ű�� �ִ� �� : int
	// int�� �޸� : 4B
	// ptr_a �� ptr_a+1�� ���� : 4B
}