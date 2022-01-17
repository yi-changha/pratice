#include <stdio.h>

struct ProductInfo {
	int num;
	const char name[100]; 
	int cost; 
};

void productSale(ProductInfo *p, int percent) {
	p->cost -= p->cost * percent / 100;	//call-by-reference
}

int main() {
	ProductInfo myProduct = { 4743683, "���� �Ѷ��", 19900 };

	productSale(&myProduct, 10);

	printf("��ǰ ��ȣ : %d\n", myProduct.num);
	printf("��ǰ �̸� : %s\n", myProduct.name);
	printf("��     �� : %d��\n\n", myProduct.cost);
}