/*
2. 범위기반 for문을 사용하여 이차원 배열을 출력해 보세요.
*/

#include <iostream>

using namespace std;

int main() {
	int arr[2][3] = {
		1, 2, 3,
		4, 5, 6
	};
	
	for (int(&ln)[3] : arr) {
		for (int &col : ln) {
			cout << col << ' ';
		}
		cout << endl;
	}
	
	for (int(*ln)[3] = arr; ln < arr + 2; ln++) {
		for (int *c = *ln; c < *ln + 3; c++) {
			cout << *c << ' ';
		}
		cout << endl;
	}
	/*  내 풀이
	for (int n : arr[0]) {
		cout << n << ' ';
		n++;
	}
	cout << endl;

	for (int n : arr[1]) {
		cout << n << ' ';
		n++;
	*/
}