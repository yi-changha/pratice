//����ü ������

#include <stdio.h>

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

void productSwap(ProductInfo *a, ProductInfo *b) {
	ProductInfo tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	ProductInfo aProduct{ 7945615, "���� �Ѷ��", 20000 };
	ProductInfo bProduct{ 5642215, "���� ������", 10000 };

	productSwap(&aProduct, &bProduct);

	printf("��ǰ ��ȣ : %d\n", aProduct.num);
	printf("��ǰ �̸� : %d\n", aProduct.name);
	printf("��     �� : %d\n", aProduct.cost);

	printf("\n");

	printf("��ǰ ��ȣ : %d\n", bProduct.num);
	printf("��ǰ �̸� : %d\n", bProduct.name);
	printf("��     �� : %d\n", bProduct.cost);
}