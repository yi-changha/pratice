#include <stdio.h>

#define FOR(I,S,E) for (int I = S; I <= E; I++)

int main() {
	FOR(i, 1, 10) {
		printf("%d ", i);
	}
}