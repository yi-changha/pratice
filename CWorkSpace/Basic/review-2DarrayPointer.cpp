/*
	1. arr == &arr[0]		ptr == &ptr[0]
	2. *arr == arr[0]
	3. ptr + 1 == ptr �� sizeof(*ptr)�� ���� ��
*/


#include <stdio.h>

int main() {
	int arr[2][3] = { { 1, 2, 3}, {4, 5, 6} };

	printf("%d\n", sizeof(arr));		//24B	sizeof(int) * 2 * 3 = 24B
	printf("%d\n", sizeof(arr[0]));		//12B	sizeof(int) * 3 = 12B
	printf("%d\n", sizeof(arr[0][0]));	//4B	sizeof(int) = 4B
	printf("\n");

	printf("%d\n", &arr);		//100���� ����	array�� ó�� �����ϴ� �ּ�
	printf("%d\n", &arr[0]);	//100			0��° ���� ó�� �����ϴ� �ּ�
	printf("%d\n", &arr[0][0]);	//100			0,0�� �ּ�
	printf("\n");


	// 2���� �迭�� �����ͷ� ġȯ�ϴ� ���
	// 2���� �迭�� �� ���� ����ų �� �ִ� �迭 �����͸� �����,
	// �迭�����Ϳ� array�� ����ִ´�.


	int(*ptr)[3] = arr;		// 3���� ���� 1���� �迭

	// 1. ptr[i] == arr[i]
	// 2. ptr[i][j] == arr[i][j]
	// => ptr == arr

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}