// ������(�Ͻ���) ����ȯ implicit conversion
// ����� ����ȯ explicit conversion

#include <iostream>
#include <string>

using namespace std;



class Item {
public:
	Item(int num) : num(num) {			// ��ȯ ������
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {	// ��ȯ ������
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name) {
		cout << "Item(int, string)" << endl;
	}

	// int���� ����ȯ ������ �����ε�
	//explicit operator int() const {		// ����� ����ȯ�� ����.
	operator int() const {
		return num;
	}
	// string������ ����ȯ ������ �����ε�
	operator string() const {
		return to_string(num) + " : " + name;
	}

	void print() {
		cout << num << " : " << name << endl;
	}

private:
	int num;
	string name;
};

void println(string s) {
	cout << s << endl;
}

void println(int n){
	cout << n << endl;
	}

int main() {
	Item i1 = Item(1);
	Item i2(2);
	Item i3 = 3;
	i3 = 3;					// ������ ��ȯ
	Item i4 = (Item)4;		// ����� ��ȯ

	Item i5(5);
	i5 = (string)"stone";

	Item i6(1, "grass");
	Item i7{ 2, "dirt" };
	i7 = { 2, "dirt" };
	Item i8{ 3, "wood" };

	int itemNum1 = (int)i8;	 // ����� ����ȯ
	int itemNum2 =	i7;		 // ������ ����ȯ
	cout << itemNum1 << endl;
	cout << itemNum2 << endl;

	println((string)i8);	// ����� ����ȯ
	println((int)i8);		// ������ ����ȯ
	//println(i8);			// ������ ����ȯ
}