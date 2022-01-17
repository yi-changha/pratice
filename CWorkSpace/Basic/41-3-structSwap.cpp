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
/*	const char 입력 시 오류 발생
	name을 const로 정의되면 상수화를 의미함.
	정의를 할 때는 const char가 아닌 char 입력
*/


int main() {
	ProductInfo myProduct = { 4743683, "제주 한라봉", 19900 };
	ProductInfo otherProduct{ 5574432, "성주 꿀참외", 10000 };

	productSwap(&myProduct, &otherProduct);

	printf("상품 번호 : %d\n", myProduct.num);
	printf("상품 이름 : %s\n", myProduct.name);
	printf("가     격 : %d원\n\n", myProduct.cost);
}
