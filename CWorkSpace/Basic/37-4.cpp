/* 4.
* ���ڿ��� �Ű������� �޾� �� ���ڿ����� ������
* �����Ͽ� ����ϴ� �Լ��� �ۼ��غ�����.
*/

#include <stdio.h>

void print_noSpace(const char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != ' ')
			printf("%c", str[i]);
	}
}

int main() {
	print_noSpace("Hello, World!\n");
	print_noSpace("My name is Lee\n");
}


// ���� �ذ���
// ��� 1: Ȯ���ڸ� .cpp���� .c�� ����
// ��� 2: char�� const char�� ��������.