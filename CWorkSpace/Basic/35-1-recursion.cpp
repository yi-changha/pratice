// 재귀 함수
// recursion

#include <stdio.h>

void rec(int n) {
	if (n > 5) return; 
	// 무한히 반복되는데 n>5. 즉, n =6 일 때 함수 종료
	// rec(6) 중간에 종료, rec(5) 종료, rec(4) 종료, ...

	printf("n = %d\n", n);
	rec(n+1);
}

int main() {
	rec(1);
}