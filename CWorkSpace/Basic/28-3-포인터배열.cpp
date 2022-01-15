// str == &str[0]

#include <stdio.h>

int main() {
	char strings[3][10] = {"Hello", "World", "!!!"};
	char *p_str[3];

	for (int i = 0; i < 3; i++) {
		p_str[i] = strings[i];
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", &strings[i][0]);
	}
}