#include <stdio.h>

int main() {
	int n;
	
	do {
		printf("제발 0을 입력해주세요!\n");
		scanf_s("%d", &n);
	} while (n != 0);

	printf("드디어 0을 입력하셨군요!\n");
}

/* while을 쓸 경우 while 안의 scanf_s를 통해 n이 정의되지 않아서
 실행되지 않음.
  먼저 1번 실행이 필요하기 때문에 do-while 사용 */