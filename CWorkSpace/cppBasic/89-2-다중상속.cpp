// 다중 상속
// 다이아몬드 문제

#include <iostream>
using namespace std;

struct Person {
	int age;	//나이
	virtual ~Person() {}
	void Eat() {
		cout << "먹는다" << endl;
	}
};
struct Student : Person {
	void Study() {
		cout << "공부" << endl;
	}
};
struct Worker : Person {
	void Work() {
		cout << "노동" << endl;
	}
};
struct Researcher : Student, Worker {

};

int main() {
	Researcher r;
	r.Student::age = 10;	// S::age, W::age 두 개가 다 있음.
	r.Worker::age = 20;
	r.Student::Eat();
	r.Worker::Eat();

	/* 다형성이 되지 않음
	Person *p = new Researcher;
	p->Eat();
	delete p;
	*/
}