#include <stdio.h>

int main() {
	int arr[10] = { 3,1,4,1,5,9,2,6,5,3 };
	
	printf("%d\n", arr); // arr == &arr[0]�� �ּҰ�
	for (int i = 3; i < 7; i++) { // 4��°���� 8��° ������
		printf("%d %d\n", arr + i, *(arr + i)); // �ּҰ�, ������
	}
}