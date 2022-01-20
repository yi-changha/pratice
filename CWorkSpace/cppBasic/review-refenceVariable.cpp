// 레퍼런스 변수
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a(5);
	int &p = a;
	p = 20;
	int b = 10;

	cout << "a = " << a << endl;
	cout << "p = " << p << endl;

	swap(a, b);
	cout << endl << "swap(a, b)" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int abc() {
	int a(5);
	int &r1 = a;
	//int &r2 = 3;		//상수 자체를 메모리에 저장하지는 않아 가리킬 수 없음.
	//int &r3 = a * 3;	//식 자체를 메모리에 저장하지는 않아 가리킬 수 없음.

	// r-value : 수정할 수 없는 값; l-value 수정할 수 있는 값.
	int a(5);
	//int &&r1 = a;		// 레퍼런스 변수를 통해 r-value 오류 안나게 가능.
	int &&r2 = 3;
	int &&r3 = a * 3;
}