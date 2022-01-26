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
	ProductInfo myProduct{ 7945615, "제주 한라봉", 20000 };

	productSale(&myProduct, 10);

	printf("상품 번호 : %d\n", myProduct.num);
	printf("상품 이름 : %d\n", myProduct.name);
	printf("가     격 : %d\n", myProduct.cost);
}