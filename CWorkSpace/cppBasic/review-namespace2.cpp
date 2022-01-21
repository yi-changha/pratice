// namespace ÁßÃ¸
#include <iostream>

using namespace std;

int n;
void set() {
	n = 10;
}

namespace lee {
	void set();
	int n;

	namespace kim {
		void set();
		int n;
	}	
}

int main() {
	using namespace lee;

	::set();
	lee::set();
	kim::set();

	cout << ::n << endl;
	cout << lee::n << endl;
	cout << kim::n << endl;
}

void lee::set() {
	n = 20;
}

void lee::kim::set() {
	n = 30;
}