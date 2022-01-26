#include <iostream>
using namespace std;

template<typename T>
int arrFnMin(const int arr[], int n, T f) {
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

	auto a = arr[1];
	auto fp = [](int n) -> int { return n * n;};
	// int (*fp)(int)= [](int n) -> int { return n * n;};

	// 람다식 (익명 함수)
	cout << arrFnMin(arr, 7, [](int n) -> int { return n * n;}) << endl;
	cout << arrFnMin(arr, 7, [](int n) -> int { return n * (n - 15) / 2;}) << endl;
}