#include <stdio.h>

int main() {
	FILE *in, *out; // ��Ʈ��
	int n;

	fopen_s(&in, "input.txt", "r");
	fopen_s(&out, "output.txt", "a");	// "w" �ʱ�ȭ �� �Է�, "a" �����Ͽ� �Է�(�߰�),
	
	fscanf_s(in, "%d", &n, 1);
	fprintf_s(out, "%d\n", n, 1);

	fclose(in);
	fclose(out);
}