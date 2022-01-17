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
	ProductInfo myProduct = { 4743683, "제주 한라봉", 19900 };

	productSale(&myProduct, 10);

	printf("상품 번호 : %d\n", myProduct.num);
	printf("상품 이름 : %s\n", myProduct.name);
	printf("가     격 : %d원\n\n", myProduct.cost);
}