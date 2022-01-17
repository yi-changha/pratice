#include <stdio.h>

struct Time {
	int h, m, s;

	int totalSec() {
		return 3600 * h + 60 * m + s;
		// 1시간 = 60분 = 3600초
		// 1분 = 60초
	}
};

int main() {
	Time t = { 1,22,48 };

	printf("%d\n", t.totalSec());
}