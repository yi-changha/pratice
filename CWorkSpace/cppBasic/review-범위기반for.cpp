// 범위 기반 for문

#include <iostream>

using namespace std;

int main() {
	cout << "C style" << endl;
	// C style
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}



	cout << endl << endl << "C++ style" << endl;
	// C++ style
	for (int n : arr) {
		cout << n << ' ';
	}

	cout << endl << endl << "n++을 해도 array값 동일" << endl;
	// n++을 해도 array값 동일
	for (int n : arr) {
		cout << n << ' ';
		n++;
	}
	
	cout << endl << endl << "레퍼런스 변수(int &n)을 써야 값 바뀜." << endl;
	for (int &n : arr) {
		cout << n << ' ';
		n++;
	}

	cout << endl;
}