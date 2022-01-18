// 난수

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	// printf("%d\n", time(NULL));	//1970/01/01 00:00:00로부터 지난 시간, 초 단위

	srand(time(NULL));
	// seed : seed의 값에 따라 난수가 달라짐.

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", rand() % 10 +1);  // 1~10까지의 난수
	}
}