// 정적 할당 : int a;
// 동적 할당 : 프로그램 실행 중에 변수를 메모리에 할당하는 것

#include <iostream>

using namespace std;

int main() {
	int *a = new int(5);

	cout << a << endl;			//주소값
	cout << *a << endl;			//가리키는 값

	*a = 10;

	cout << a << endl;		
	cout << *a << endl;

	delete a;					//메모리 해제
}
