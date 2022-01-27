// 정적 바인딩
// override : 우선하다

#include <iostream>
using namespace std;

class Base {
public:
	void Print() {
		cout << "Base" << endl;
	}
};

class Derived : public Base {
public:
	void Print() {
		cout << "Derived" << endl;
	}
};

class Derived2 :public Base {

};

int main() {
	Base *b = new Derived();
	b->Print();
	b = new Derived2();
	b->Print();
}