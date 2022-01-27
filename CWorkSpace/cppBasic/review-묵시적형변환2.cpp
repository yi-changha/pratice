// 묵시적(암시적) 형변환 implicit conversion
// 명시적 형변환 explicit conversion

#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	Item(int num) : num(num) {	// 변환 생성자
		cout << "Item(int)" << endl;
	}
	Item(string name) : name(name) {
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name) {
		cout << "Item(int, string)" << endl;
	}

	// int로의 형변환 연산자 오버로딩
	explicit operator int() const {
		return num;
	}

	// string으로의 형변환 연산자 오버로딩
	explicit operator string() const {
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

void println(int n) {
	cout << n << endl;
}

int main() {
	Item i1 = Item(1);
	Item i2(2);
	Item i3 = 3;
	i3 = 3; // 묵시적 변환
	Item i4 = (Item)3; // 명시적 변환

	Item i5(5);
	i5 = string("stone");

	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };
	i7 = { 2, "dirt" };
	Item i8{ 3, "wood" };

	int itemNum = (int)i8;	//명시적 형변환
	//int itemNum2 = i7;		//묵시적 형변환 explicit 사용으로 막힘.
	cout << itemNum << endl;

	println((string)i8);	//명시적 형변환
	println((int)i8);
}