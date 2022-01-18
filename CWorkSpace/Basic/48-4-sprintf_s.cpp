#include <stdio.h>

int main() {
	int n = 450;
	char str[100];
	
	sprintf_s(str, "%d", n);
	printf("%s\n", str);
}