#include <stdio.h>

// ��������
int itemCnt = 0;
int money = 100;

int buyItem(int cost, int cnt) {
	if (money < cost) {
		printf("�ܾ��� �����մϴ�.\n");
		return -1;
	}

	itemCnt += cnt;
	money -= cost;
	printf("�������� �����߽��ϴ�. \n");
	printf(" ������ ���� : %d\n", itemCnt);
	printf(" �ܾ� : %d\n", money);
	return 0;
}

int main() {
	int result;

	result = buyItem(3000, 500);

	if (result == -1) {
		printf("���� �����Ͻñ���...\n");
	}
	
	buyItem(30, 5);

	buyItem(50, 7);


}