//구조체 포인터

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
	ProductInfo aProduct{ 7945615, "제주 한라봉", 20000 };
	ProductInfo bProduct{ 5642215, "성주 꿀참외", 10000 };

	productSwap(&aProduct, &bProduct);

	printf("상품 번호 : %d\n", aProduct.num);
	printf("상품 이름 : %d\n", aProduct.name);
	printf("가     격 : %d\n", aProduct.cost);

	printf("\n");

	printf("상품 번호 : %d\n", bProduct.num);
	printf("상품 이름 : %d\n", bProduct.name);
	printf("가     격 : %d\n", bProduct.cost);
}