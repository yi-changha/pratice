#include <iostream>

using namespace std;

int n;
void set() {
	n = 10;
}

namespace lee {
	void set();

	namespace google {
		void set();
		int n;
	}
	int n;
}

int main() {
	::set();
	lee::set();
	lee::google::set();

	cout << ::n << endl;			//30
	cout << lee::n << endl;			//0
	cout << lee::google::n << endl;	//0
}
// int n;�� set()�ڿ� ��ġ�ϸ� �տ� int n;�� ã�� �ű⿡ ���� ������.
// ������ n���� ��ȭ�� ���� 0�� ��µ�.

void lee::set() {
	n = 20;
}

void lee::google::set() {
	n = 30;
}

// ���� set()�Լ��� int n;�� ���縦 ���� �˰�, ������ ������.