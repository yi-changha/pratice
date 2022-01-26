//스마트 포인터
//weak_ptr

#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test(int x) : x(x) { cout << "생성자" << endl; }
	~Test() { cout << "소멸자" << endl; }
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	weak_ptr<Test> b;
	{
		shared_ptr<Test> a(new Test(5));
		b = a;
		cout << a.use_count() << endl;		//1
		cout << b.use_count() << endl;		//1
		if (b.expired()) {
			cout << b.lock()->GetX() << endl;		//5
			// 만약 객체가 살아있다면, lock을 통해 shared_ptr을 불러오고, GetX()
		}
	}	// shared_ptr<Test> a 소멸
	cout << b.use_count() << endl;		//0
	if (b.expired()) {
		cout << b.lock()->GetX() << endl;
	}
	//weak_ptr은 가리키고 있는 객체가 이미 소멸되어 있을 수 있음.
}	// weak_ptr<Test> a 소멸