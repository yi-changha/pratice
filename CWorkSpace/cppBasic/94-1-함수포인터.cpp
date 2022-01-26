// 함수 포인터

#include <iostream>
using namespace std;

bool compare(int a, int b) {
	return a == b;
}

int main() {
	bool(*fp)(int, int) = compare;		// 역참조, int 두 개를 받아 bool을 return
	//fp = compare;				// 함수 포인터, &compare == compare
	bool res = fp(2, 2);		// 함수 포인터, *fp() == fp()
	
	cout << res << endl;
}