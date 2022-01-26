//스마트 포인터
//shared_ptr

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
	shared_ptr<Test> a(new Test(5));
	{
		shared_ptr<Test> b = a;
		cout << a.use_count() << endl;		//2
		cout << b.use_count() << endl;		//2
	}	// shared_ptr<Test> b 소멸
	cout << a.use_count() << endl;		//1
}	// shared_ptr<Test> a 소멸