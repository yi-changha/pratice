#include <stdio.h>

// call-by-value : 값만
// call-by-reference : 참조

void printArr(int arr[4]) { // arr[4] == *arr
	for (int i = 0; i < 4; i++) {
		arr[i] *= 2; // arr[i] == *(arr+i)
	}
}

int main() {
	int arr[4] = { 1, 2, 3, 4 };

	printArr(arr); // arr == &arr[0]

	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]); // 2 4 6 8 // call-by-reference
	}
}