#include <stdio.h>

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

int main() {
	ProductInfo myProduct{ 7945615, "제주 한라봉", 20000 };

	ProductInfo *ptr_product = &myProduct;

	printf("상품 번호 : %d\n", ptr_product->num);
	printf("상품 이름 : %d\n", ptr_product->name);
	printf("가     격 : %d\n", ptr_product->cost);

	//ptr_product->num : ptr이 가리키는 것의 구성성분 중 num

	/*
	printf("상품 번호 : %d\n", (*ptr_product).num);
	printf("상품 이름 : %d\n", (*ptr_product).name);
	printf("가     격 : %d\n", (*ptr_product).cost);
	*/
}