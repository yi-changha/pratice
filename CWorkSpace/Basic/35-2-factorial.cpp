// 팩토리얼
// 5! = 5*4*3*2*1 = 120
// n! = n*(n-1)!

#include <stdio.h>

// n을 매개변수 -> n!을 return
int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
// ex) factorial(n=3), factorial(n=2), factorial(n=2), factorial(n=1) // return 1;
//      3*factorial(2), 2*factorial(1), return 1;
//      3*2*1 = 6


int main() {
	printf("%d\n", factorial(5));
}