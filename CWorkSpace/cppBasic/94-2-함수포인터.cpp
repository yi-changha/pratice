// 함수 포인터
#include <iostream>
using namespace std;

int square(int x) { return x * x; }
int myFunc(int x) { return x * (x - 15) / 2; }

int arrFnMin(const int arr[], int n, int (*f)(int)) {
	int min = f(arr[0]);
	for (int i = 1; i < n; i++) {
		if (f(arr[i]) < min) {
			min = f(arr[i]);
		}
	}
	return min;
}

int main() {
	int arr[7] = { 3, 1, -4, 1, 5, 9, -2 };
	cout << arrFnMin(arr, 7, square) << endl;
	cout << arrFnMin(arr, 7, myFunc) << endl;
}