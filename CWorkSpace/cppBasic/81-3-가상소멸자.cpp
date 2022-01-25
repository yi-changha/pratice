// 가상 소멸자
// 소멸자는 엥간해서 virtual 가상으로 해주는게 좋음.
// 부모클래스의 포인터가 자식클래스의 포인터를 가리키는 특수한 상황에서
// 자식클래스의 소멸자가 호출되게 하기 위해선 가상 소멸자 요구됨.

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

class Bingsoo {
public:
	Bingsoo() {
		cout << "Bingsoo()" << endl;
		ice = new Ice;	
	}
	virtual ~Bingsoo() {
		cout << "~Bingsoo()" << endl;
		delete ice;
	}

private:
	Ice *ice;
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo()" << endl;
		pat = new Pat;
	}
	 ~PatBingsoo() { 
		cout << "~PatBingsoo()" << endl; 
		delete pat;						
	}

private:
	Pat *pat;
};

int main() {
	Bingsoo *p = new PatBingsoo;
	delete p;
}