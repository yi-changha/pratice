#include <stdio.h>

struct ProductInfo {
	int num; // 4B
	const char name[100]; //100B
	int cost; // 4B
};
// ���� : 108B


int main() {
	ProductInfo myProduct = { 4743683, "���� �Ѷ��", 19900 };

	printf("��ǰ ��ȣ : %d\n", myProduct.num);
	printf("��ǰ �̸� : %s\n", myProduct.name);
	printf("��     �� : %d��\n\n", myProduct.cost);

	printf("�ּҰ� : %d\n", &myProduct); // �ּҰ� : 100 ����
	printf("��ǰ ��ȣ : %d\n", &myProduct.num); // 100
	printf("��ǰ �̸� : %d\n", myProduct.name); // 104	// 100+4
	printf("��     �� : %d\n", &myProduct.cost); // 204	// 100+4+100

	printf("sizeof(myProduct) = %d\n", sizeof(myProduct));	//108B
}