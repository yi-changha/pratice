// �迭 ������

#include <stdio.h>

int main() {
	int arr[3] = { 1, 2, 3 };

	int(*ptr_arr)[3]; // ���� 3�� int�� �迭�� ����Ű�� �����͸� ����
	ptr_arr = &arr;

	printf("&arr = %d\n", &arr);				//100���� ����
	printf("ptr_arr = %d\n", ptr_arr);			//100
	printf("\n");
	printf("&arr + 1 = %d\n", &arr + 1);		//112
	printf("ptr_arr + 1 = %d\n", ptr_arr +1);	//112
	printf("\n");

	for (int i = 0; i < 3; i++) {
		printf("%d ", (*ptr_arr)[i]);			//1 2 3
	}
}