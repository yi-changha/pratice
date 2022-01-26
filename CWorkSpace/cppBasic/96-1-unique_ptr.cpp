//����Ʈ ������

#include <iostream>
#include <memory>
using namespace std;

// unique_ptr, shared_ptr, weak_ptr

class Test {
public:
	Test(int x) : x(x) { cout << "������" << endl; }
	~Test() { cout << "�Ҹ���" << endl; }
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	//unique_ptr<int> a(new int(5));
	//unique_ptr<int> b(a.release());	// ������ ����
	//cout << *b << endl;
	unique_ptr<Test> a(new Test(5));
	cout << a->GetX() << endl;
	cout << "====" << endl;
	a.reset(new Test(6));
	cout << a->GetX() << endl;
	cout << "====" << endl;
}