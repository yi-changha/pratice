#include <stdio.h>

struct ProductInfo {
	int num; // 4B
	const char name[100]; //100B
	int cost; // 4B
};
// 도합 : 108B


int main() {
	ProductInfo myProduct = { 4743683, "제주 한라봉", 19900 };

	printf("상품 번호 : %d\n", myProduct.num);
	printf("상품 이름 : %s\n", myProduct.name);
	printf("가     격 : %d원\n\n", myProduct.cost);

	printf("주소값 : %d\n", &myProduct); // 주소값 : 100 기준
	printf("상품 번호 : %d\n", &myProduct.num); // 100
	printf("상품 이름 : %d\n", myProduct.name); // 104	// 100+4
	printf("가     격 : %d\n", &myProduct.cost); // 204	// 100+4+100

	printf("sizeof(myProduct) = %d\n", sizeof(myProduct));	//108B
}