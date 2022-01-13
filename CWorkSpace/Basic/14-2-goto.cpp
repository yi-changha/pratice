# include <stdio.h>

int main() {
	int i = 1;

	repeat:
	printf("%d\n", i);
	if (i < 10) {
		i++;
		goto repeat;
	}
}