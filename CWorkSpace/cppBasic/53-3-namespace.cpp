#include <iostream>

int n;
void set() {
	n = 10;
}

namespace lee {
	int n;
	void set() {
		n = 20;
	}
	namespace google {
		int n;
		void set() {
			n = 30;
		}
	}
}

int main() {
	using namespace std;
	using namespace lee;

	::set();		// :: ���� �Ұ�
	lee::set();		// lee:: ���� �Ұ�
	google::set();	// lee:: ���� ����

	cout << ::n << endl;
	cout << lee::n << endl;
	cout << lee::google::n << endl;
}