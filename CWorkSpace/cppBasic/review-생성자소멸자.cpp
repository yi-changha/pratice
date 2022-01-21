// 생성자 : 객체가 생성될 때 자동으로 호출되는 함수
// 소멸자 : 객체가 소멸될 때 자동으로 호출되는 함수

#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() {		// 생성자
		cout << "생성자 호출" << endl;
	}
	
	~MyClass() {	// 소멸자
		cout << "소멸자 호출" << endl;
	}
};

// MyClass global1Obj;

void testLocal1Obj() {
	cout << "testLocalObj 함수 시작" << endl;
	MyClass local10bj;
	cout << "testLocalObj 함수 끝" << endl;
}

int main() {
	cout << "main함수 시작" << endl;
	testLocal1Obj();
	cout << "main함수 끝" << endl;
}