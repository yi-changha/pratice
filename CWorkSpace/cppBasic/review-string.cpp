#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	str = "Hello";			// �迭 ���°� �ƴϱ� ������ ���� ����X
	cout << str << endl;

	// ���ڿ����� ���̴� �͵� ������.
	string name;

	cout << "�̸� �Է� : ";
	cin >> name;

	string message = "�ȳ��ϼ���, " + name + " ��. ";
	cout << message << endl;
}