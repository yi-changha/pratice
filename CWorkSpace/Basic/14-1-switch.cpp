// switch
// goto

# include <stdio.h>

int main() {
	int choice;

	makeChoice:

	printf("새 게임 : 1\n");
	printf("불러오기 : 2\n");
	printf("설정 : 3\n");
	printf("크레딧 : 4\n");

	scanf_s("%d", &choice, 1);

	switch (choice) {
	case 1:
		printf("새 게임을 시작합니다.\n");
		break;

	case 2:
		printf("저장된 게임을 불러옵니다.\n");
		break;

	case 3:
		printf("설정을 불러옵니다.\n");
		break;

	case 4:
		printf("크레딧을 불러옵니다.\n");
		break;

	default :
		printf("잘못 입력하셨습니다.\n");
		goto makeChoice;
		break;
	}
/*
	if (choice == 1) {
		printf("새 게임을 시작합니다.\n");
	}
	else if (choice == 2) {
		printf("저장된 게임을 불러옵니다.\n");
	}
	else if (choice == 3) {
		printf("설정을 불러옵니다.\n");
	}
	else if (choice == 4) {
		printf("크레딧을 불러옵니다.\n");
	}
	else {
		printf("잘못 입력하셨습니다.\n");
	}
*/
}