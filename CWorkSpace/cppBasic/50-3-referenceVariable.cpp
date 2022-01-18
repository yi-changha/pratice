// 레퍼런스 변수

#include <iostream>

using namespace std;

int main() {
	// r-value : 수정 가능한 값, l-value : 수정 불가능한 값.

	int a(5);
	int &&r2 = 3;
	int &&r3 = a * a;


}