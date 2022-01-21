// namespace
#include <iostream>

using namespace std;

int n;
void set();
namespace lee {
	int n;
	void set();
}

namespace kim {
	int n;
	void set();
}

int main() {
	::set();
	lee::set();
	kim::set();

	cout << ::n << endl;		//30
	cout << lee::n << endl;		//20
	cout << kim::n << endl;		//0
}

void ::set() {
	n = 10;
}

void lee::set() {
	n = 20;
}


void kim::set() {
	::n = 30;
}