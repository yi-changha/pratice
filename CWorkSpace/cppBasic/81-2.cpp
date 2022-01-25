// ����/�Ҹ��� ���� ����
// �����͸� ȣ���ϴ� ���

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


// ice�� ����Ű�� �����͸� ȣ���� ���.
// �����ʹ� ��ü�� �ƴϱ� ������ �����Ͱ� ���� ���� ������ ȣ�� �ȵ�. 
// ������ ���� -> Bingsoo ������ -> Ice ������ ȣ��
class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl;
		ice = new Ice;		// Bingsoo�� ȣ��Ǳ� ���ؼ��� ice�� ȣ��Ǿ�� ��.
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