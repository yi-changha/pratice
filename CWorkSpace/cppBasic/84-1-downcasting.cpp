//다운캐스팅 dynamic_cast
// static_cast : 정적 (컴파일)
// dynamic_cast : 동적 (런타임)

// RTTI (Run Time Type Information/Identicfication)

#include <iostream>

using namespace std;

class Base {	
public:
	virtual void f() {}
	int x;
};

class Derived : public Base {
public:
	void f() {}
	int y;
};

int main() {
	cout << sizeof(Base) << endl;	
	cout << sizeof(Derived) << endl;	
}