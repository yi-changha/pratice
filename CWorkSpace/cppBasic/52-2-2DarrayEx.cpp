/*
2. ������� for���� ����Ͽ� ������ �迭�� ����� ������.
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
	/*  �� Ǯ��
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