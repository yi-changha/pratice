//스마트 포인터

#include <iostream>
#include <memory>
using namespace std;

// unique_ptr, shared_ptr, weak_ptr

class Test {
public:
	Test(int x) : x(x) { cout << "생성자" << endl; }
	~Test() { cout << "소멸자" << endl; }
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	//unique_ptr<int> a(new int(5));
	//unique_ptr<int> b(a.release());	// 소유권 이전
	//cout << *b << endl;
	unique_ptr<Test> a(new Test(5));
	cout << a->GetX() << endl;
	cout << "====" << endl;
	a.reset(new Test(6));
	cout << a->GetX() << endl;
	cout << "====" << endl;
}