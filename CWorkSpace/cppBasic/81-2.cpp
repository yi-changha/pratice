// 생성/소멸자 실행 순서
// 포인터를 호출하는 경우

#include <iostream>

using namespace std;

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};


// ice가 가리키는 포인터를 호출할 경우.
// 포인터는 객체가 아니기 때문에 포인터가 생길 때는 생성자 호출 안됨. 
// 포인터 생성 -> Bingsoo 생성자 -> Ice 생성자 호출
class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl;
		ice = new Ice;		// Bingsoo가 호출되기 위해서는 ice가 호출되어야 함.
	}
	~Bingsoo() { 
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}

private:
	Ice *ice;
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { cout << "PatBingsoo()" << endl; }
	~PatBingsoo() { cout << "~PatBingsoo()" << endl; }

private:
	Pat pat;
};

int main() {
	PatBingsoo *p = new PatBingsoo;
	delete p;
}