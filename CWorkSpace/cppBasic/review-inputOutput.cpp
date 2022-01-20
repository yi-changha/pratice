#include <iostream>

using namespace std;

int main() {
	// 출력
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Hello, World!" << "\n";
	cout << "정수 두 개를 입력해주세요" << endl << endl;
	
	int a, b;
	// 입력
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
}