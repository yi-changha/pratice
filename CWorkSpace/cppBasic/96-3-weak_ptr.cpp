//����Ʈ ������
//weak_ptr

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
	weak_ptr<Test> b;
	{
		shared_ptr<Test> a(new Test(5));
		b = a;
		cout << a.use_count() << endl;		//1
		cout << b.use_count() << endl;		//1
		if (b.expired()) {
			cout << b.lock()->GetX() << endl;		//5
			// ���� ��ü�� ����ִٸ�, lock�� ���� shared_ptr�� �ҷ�����, GetX()
		}
	}	// shared_ptr<Test> a �Ҹ�
	cout << b.use_count() << endl;		//0
	if (b.expired()) {
		cout << b.lock()->GetX() << endl;
	}
	//weak_ptr�� ����Ű�� �ִ� ��ü�� �̹� �Ҹ�Ǿ� ���� �� ����.
}	// weak_ptr<Test> a �Ҹ�