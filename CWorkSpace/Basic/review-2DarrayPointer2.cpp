//�ѱ�

#include <stdio.h>

int main() {
	int arr[2][3] = {
		1, 2, 3,
		4, 5, 6
	};

	for (int(*row)[3] = arr; row < arr + 2; row++) {
		// row[3] �� ����, 2������ ����.
		for (int *col = *row; col < *row + 3; col++) {
			// col = *row == *(&row[3])	== row[3]
			printf("%d", *col);
			// *col = *row[3] == row[][]	row�� ���� ������ ��.
		}
		printf("\n");
	}
}