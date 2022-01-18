#include <stdio.h>

int main() {
	FILE *in, *out; // 스트림
	int n;

	fopen_s(&in, "input.txt", "r");
	fopen_s(&out, "output.txt", "a");	// "w" 초기화 후 입력, "a" 유지하여 입력(추가),
	
	fscanf_s(in, "%d", &n, 1);
	fprintf_s(out, "%d\n", n, 1);

	fclose(in);
	fclose(out);
}