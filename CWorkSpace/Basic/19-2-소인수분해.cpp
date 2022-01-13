// 자연수 입력 : 12
// 1, 2, 3, 4, 6, 12,

#include <stdio.h>

int main() {
	int n;
	int i;
	scanf_s("%d\n", &n, 1);
	
	if (n > 0) {
		for (i = 1; i <= n; i++) {
			if (n % i == 0)
				printf("%d, ", i);
		}
	}
	else {
		printf("자연수를 입력해주세요.");
	}

}