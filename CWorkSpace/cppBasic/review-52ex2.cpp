/*
2. 범위 기반 for문을 사용하여 이차원 배열을 출력해보세요.
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
}