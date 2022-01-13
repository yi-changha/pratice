// 두 문자를 비교, 사전 순으로 누가 먼저 있는지도 알아냄
#include <stdio.h>
#include <string.h>

int main() {
	char str1[] = "sample";
	char str2[] = "simple";
	char str3[] = "simple";

	//int cmp = strcmp(str1, str2); // -1 : str1이 사전순으로 앞쪽에 있어서
	//int cmp = strcmp(str2, str1); // 1
	int cmp = strcmp(str2, str3); // 0 : 같기 때문

	printf("%d\n", cmp);
}