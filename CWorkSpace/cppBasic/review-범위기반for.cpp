// ���� ��� for��

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

	cout << endl << endl << "n++�� �ص� array�� ����" << endl;
	// n++�� �ص� array�� ����
	for (int n : arr) {
		cout << n << ' ';
		n++;
	}
	
	cout << endl << endl << "���۷��� ����(int &n)�� ��� �� �ٲ�." << endl;
	for (int &n : arr) {
		cout << n << ' ';
		n++;
	}

	cout << endl;
}