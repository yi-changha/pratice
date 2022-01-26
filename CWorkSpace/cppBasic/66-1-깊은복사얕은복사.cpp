//깊은 복사, 얕은 복사

#include <iostream>
using namespace std;


int main() {
	int *a = new int(5);
	int *b = new int(3);

	a = b;		// 얕은 복사 (참조만 복사)	, 주소값 변경
	*a = *b;	// 깊은 복사 (값을 복사)	, 메모리에 있는 값 변경
	
	delete a;
	delete b;
}