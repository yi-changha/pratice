#include <stdio.h>

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

int main() {
	ProductInfo myProduct{ 7945615, "���� �Ѷ��", 20000 };

	ProductInfo *ptr_product = &myProduct;

	printf("��ǰ ��ȣ : %d\n", ptr_product->num);
	printf("��ǰ �̸� : %d\n", ptr_product->name);
	printf("��     �� : %d\n", ptr_product->cost);

	//ptr_product->num : ptr�� ����Ű�� ���� �������� �� num

	/*
	printf("��ǰ ��ȣ : %d\n", (*ptr_product).num);
	printf("��ǰ �̸� : %d\n", (*ptr_product).name);
	printf("��     �� : %d\n", (*ptr_product).cost);
	*/
}