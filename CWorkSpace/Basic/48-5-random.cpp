// ����

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	// printf("%d\n", time(NULL));	//1970/01/01 00:00:00�κ��� ���� �ð�, �� ����

	srand(time(NULL));
	// seed : seed�� ���� ���� ������ �޶���.

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", rand() % 10 +1);  // 1~10������ ����
	}
}