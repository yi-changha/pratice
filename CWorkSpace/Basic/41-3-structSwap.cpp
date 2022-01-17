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
/*	const char �Է� �� ���� �߻�
	name�� const�� ���ǵǸ� ���ȭ�� �ǹ���.
	���Ǹ� �� ���� const char�� �ƴ� char �Է�
*/


int main() {
	ProductInfo myProduct = { 4743683, "���� �Ѷ��", 19900 };
	ProductInfo otherProduct{ 5574432, "���� ������", 10000 };

	productSwap(&myProduct, &otherProduct);

	printf("��ǰ ��ȣ : %d\n", myProduct.num);
	printf("��ǰ �̸� : %s\n", myProduct.name);
	printf("��     �� : %d��\n\n", myProduct.cost);
}
