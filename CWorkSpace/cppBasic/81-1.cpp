// 생성/소멸자 실행 순서

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
	Bingsoo() { cout << "Bingsoo()" << endl; }
	~Bingsoo() { cout << "~Bingsoo()" << endl; }

private:
	Ice ice;
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

// 멤버가 생긴 이후 생성자가 호출된다 
//: 멤버들을 초기화해야하니까, 멤버들이 일단 있어야한다!
// 부모 클래스가 먼저 호출 -> 파생 클래스
// Ice -> Bingsoo -> Pat -> PatBingsoo

// 소멸은 역순
// PatBingsoo -> Pat -> Bingsoo -> Ice
// 파생 클래스가 먼저 사라지고 부모 클래스가 사라짐.
// 클래스의 멤버가 있는 상태로 소멸자가 호출되어야 유효함.