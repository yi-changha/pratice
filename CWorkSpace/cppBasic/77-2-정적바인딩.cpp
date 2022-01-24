//정적 바인딩

#include <iostream>

using namespace std;

class Base {
public:
	void Print() {
		cout << "From Base" << endl;
	}
};


class Derived : public Base {
public:
	void Print() {
		cout << "From Derived" << endl;
	}
};

class Derived : public Base {

};

int main() {
	Base *b = new Derived();
	b->Print();							//base
	b = new Derived();
	b->Print();
}