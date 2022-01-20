#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	str = "Hello";			// 배열 형태가 아니기 때문에 길이 제한X
	cout << str << endl;

	// 문자열끼리 붙이는 것도 간단함.
	string name;

	cout << "이름 입력 : ";
	cin >> name;

	string message = "안녕하세요, " + name + " 님. ";
	cout << message << endl;
}