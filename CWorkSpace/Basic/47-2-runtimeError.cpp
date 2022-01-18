#include <stdio.h>

int main() {
	FILE *in, *out; // ½ºÆ®¸²
	int n;

	fopen_s(&in, "intput.txt", "r");
	
	if (in != nullptr) {
		fscanf_s(in, "%d", &n, 1);
		printf("%d\n", n);
		fclose(in);
	}
}