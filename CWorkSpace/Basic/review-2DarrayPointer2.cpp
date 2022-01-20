//한글

#include <stdio.h>

int main() {
	int arr[2][3] = {
		1, 2, 3,
		4, 5, 6
	};

	for (int(*row)[3] = arr; row < arr + 2; row++) {
		// row[3] 행 생성, 2열까지 진행.
		for (int *col = *row; col < *row + 3; col++) {
			// col = *row == *(&row[3])	== row[3]
			printf("%d", *col);
			// *col = *row[3] == row[][]	row의 구성 성분의 값.
		}
		printf("\n");
	}
}