#include <iostream>

using namespace std;

int n;
void set() {
	n = 10;	// :: 전역 변수 명시
}

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

	cout << ::n << endl;	
	cout << lee::n << endl;	
	cout << kim::n << endl; 
}

void lee::set() {
		n = 20;
}

void kim::set() {
		n = 30;
}