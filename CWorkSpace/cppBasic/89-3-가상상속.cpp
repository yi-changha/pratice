//���� ���
// ������, Student�� Worker�� Eat()�� �����ϰ� �Ǹ�, ��ȣ�� �߻�.

// ���� ����� �������̽��κ��͸� �޴´�.
// �������̽� : ��� �޼��尡 ���� ���� �Լ��̰� (������)��� ������ ���� Ŭ����
// �߻� Ŭ���� : ���� ���� �Լ��� �ϳ� �̻� ��� �ִ� Ŭ����
// ������ Ŭ���� : ���� �Լ��� �ϳ� �̻� ��� �ִ� Ŭ����

#include <iostream>
using namespace std;

struct IPerson {
	virtual ~IPerson() {}
	virtual void Eat() = 0;
	virtual int GetAge() = 0;
};
struct IStudent : virtual IPerson {
	virtual void Study() = 0;
};
struct Student : IStudent {
	void Eat() {
		cout << "�ȳ�" << endl;
	}
	void Study() {
		cout << "�н�" << endl;
	}
	int GetAge() { return age; }
	int age;
};
struct IWorker : virtual IPerson {
	virtual void Work() = 0;
};
struct Researcher : IStudent, IWorker {
	void Eat() {
		cout << "�Ļ�" << endl;
	}
	void Study() {
		cout << "�н�" << endl;
	}
	void Work() {
		cout << "�뵿" << endl;
	}
	int GetAge() { return age; }
	int age;
};

int main() {
	IPerson *p = new Researcher;
	p->GetAge();
	delete p;
	Student s;
	s.Study();
}