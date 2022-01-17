//type def 
// 형을 정의
#include <stdio.h>

int main() {
	typedef int Pair[2];
	Pair point = { 3, 4 };	// int point[2] { 3, 4 };

	printf("(%d, %d)\n", point[0], point[1]);
}