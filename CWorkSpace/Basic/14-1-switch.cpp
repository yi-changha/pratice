// switch
// goto

# include <stdio.h>

int main() {
	int choice;

	makeChoice:

	printf("�� ���� : 1\n");
	printf("�ҷ����� : 2\n");
	printf("���� : 3\n");
	printf("ũ���� : 4\n");

	scanf_s("%d", &choice, 1);

	switch (choice) {
	case 1:
		printf("�� ������ �����մϴ�.\n");
		break;

	case 2:
		printf("����� ������ �ҷ��ɴϴ�.\n");
		break;

	case 3:
		printf("������ �ҷ��ɴϴ�.\n");
		break;

	case 4:
		printf("ũ������ �ҷ��ɴϴ�.\n");
		break;

	default :
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
		goto makeChoice;
		break;
	}
/*
	if (choice == 1) {
		printf("�� ������ �����մϴ�.\n");
	}
	else if (choice == 2) {
		printf("����� ������ �ҷ��ɴϴ�.\n");
	}
	else if (choice == 3) {
		printf("������ �ҷ��ɴϴ�.\n");
	}
	else if (choice == 4) {
		printf("ũ������ �ҷ��ɴϴ�.\n");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
*/
}