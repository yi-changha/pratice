#include <stdio.h>

struct Time {
	int h, m, s;

	int totalSec() {
		return 3600 * h + 60 * m + s;
		// 1�ð� = 60�� = 3600��
		// 1�� = 60��
	}
};

int main() {
	Time t = { 1,22,48 };

	printf("%d\n", t.totalSec());
}