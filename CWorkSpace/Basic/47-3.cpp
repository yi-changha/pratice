#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	FILE *in = fopen("47-3.cpp", "r");
	char ch;
	while (fscanf(in, "%c", &ch) != EOF) {
		printf("%c", ch);
	}

	fclose(in);
}