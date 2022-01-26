//����Ʈ ������
//shared_ptr

#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test(int x) : x(x) { cout << "������" << endl; }
	~Test() { cout << "�Ҹ���" << endl; }
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
	}	// shared_ptr<Test> b �Ҹ�
	cout << a.use_count() << endl;		//1
}	// shared_ptr<Test> a �Ҹ�