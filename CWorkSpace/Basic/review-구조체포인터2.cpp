#include <stdio.h>

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

void productSale(ProductInfo *p, int percent) {
	p->cost -= p->cost * percent / 100;
}

int main() {
	ProductInfo myProduct{ 7945615, "���� �Ѷ��", 20000 };

	productSale(&myProduct, 10);

	printf("��ǰ ��ȣ : %d\n", myProduct.num);
	printf("��ǰ �̸� : %d\n", myProduct.name);
	printf("��     �� : %d\n", myProduct.cost);
}