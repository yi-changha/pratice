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
// int n;이 set()뒤에 위치하면 앞에 int n;을 찾고 거기에 값을 대입함.
// 나머지 n값은 변화가 없어 0을 출력됨.

void lee::set() {
	n = 20;
}

void lee::google::set() {
	n = 30;
}

// 위에 set()함수는 int n;의 존재를 먼저 알고, 각각에 대입함.