//가상 상속
// 하지만, Student와 Worker에 Eat()이 존재하게 되면, 모호성 발생.

// 다중 상속은 인터페이스로부터만 받는다.
// 인터페이스 : 모든 메서드가 수순 가상 함수이고 (비정적)멤버 변수는 없는 클래스
// 추상 클래스 : 순수 가상 함수가 하나 이상 들어 있는 클래스
// 다형적 클래스 : 가상 함수가 하나 이상 들어 있는 클래스

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
		cout << "냠냠" << endl;
	}
	void Study() {
		cout << "학습" << endl;
	}
	int GetAge() { return age; }
	int age;
};
struct IWorker : virtual IPerson {
	virtual void Work() = 0;
};
struct Researcher : IStudent, IWorker {
	void Eat() {
		cout << "식사" << endl;
	}
	void Study() {
		cout << "학습" << endl;
	}
	void Work() {
		cout << "노동" << endl;
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