// ����/�Ҹ��� ���� ����

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

// ����� ���� ���� �����ڰ� ȣ��ȴ� 
//: ������� �ʱ�ȭ�ؾ��ϴϱ�, ������� �ϴ� �־���Ѵ�!
// �θ� Ŭ������ ���� ȣ�� -> �Ļ� Ŭ����
// Ice -> Bingsoo -> Pat -> PatBingsoo

// �Ҹ��� ����
// PatBingsoo -> Pat -> Bingsoo -> Ice
// �Ļ� Ŭ������ ���� ������� �θ� Ŭ������ �����.
// Ŭ������ ����� �ִ� ���·� �Ҹ��ڰ� ȣ��Ǿ�� ��ȿ��.