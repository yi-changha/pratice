// ����ü ������

#include <stdio.h>

struct ProductInfo {
	int num;
	const char name[100];
	int cost;
};

int main() {
	ProductInfo myProduct = { 4743683, "���� �Ѷ��", 19900 };

	ProductInfo *ptr_product = &myProduct;

	// (*a).b == a->b

	printf("��ǰ ��ȣ : %d\n", ptr_product->num); // (*ptr_product).num
	printf("��ǰ �̸� : %s\n", ptr_product->name);
	printf("��     �� : %d��\n\n", ptr_product->cost);
}