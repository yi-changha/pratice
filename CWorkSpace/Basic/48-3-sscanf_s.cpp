// sscanf / sprintf

#include <stdio.h>

int main() {
	char str[] = "450";
	int n;

	sscanf_s(str, "%d", &n);
	printf("n�� �� : %d\n", n);
}