// 다중 상속
// 다이아몬드 문제

#include <iostream>
using namespace std;

struct Person {
	int a;
};
struct Mom : Person {
	Mom() {
		a = 1;
	}
};
struct Dad : Person {
	Dad() {
		a = 2;
	}
};
struct Child : Mom, Dad {
	int c = 3;
};

int main() {
	Child ch;
	cout << ch.Mom::a << endl;	// ch.a 에러 발생. :: 소속 밝히기
	cout << ch.Dad::a << endl;	
	cout << ch.c << endl;
}