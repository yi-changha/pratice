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

	::set();		// :: 생략 불가
	lee::set();		// lee:: 생략 불가
	google::set();	// lee:: 생략 가능

	cout << ::n << endl;
	cout << lee::n << endl;
	cout << lee::google::n << endl;
}