// ���� ���
// ���̾Ƹ�� ����

#include <iostream>
using namespace std;

struct Person {
	int age;	//����
	virtual ~Person() {}
	void Eat() {
		cout << "�Դ´�" << endl;
	}
};
struct Student : Person {
	void Study() {
		cout << "����" << endl;
	}
};
struct Worker : Person {
	void Work() {
		cout << "�뵿" << endl;
	}
};
struct Researcher : Student, Worker {

};

int main() {
	Researcher r;
	r.Student::age = 10;	// S::age, W::age �� ���� �� ����.
	r.Worker::age = 20;
	r.Student::Eat();
	r.Worker::Eat();

	/* �������� ���� ����
	Person *p = new Researcher;
	p->Eat();
	delete p;
	*/
}