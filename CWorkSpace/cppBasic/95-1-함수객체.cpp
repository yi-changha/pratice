// ÇÔ¼ö °´Ã¼ (functin object/fucntor)

#include <iostream>
using namespace std;

class Equals {
public:
	Equals(int value) : value(value) {}
	bool operator()(int x) const {
		return x == value;
	}
	bool operator()(int x, int y) const {
		return x + y == value;
	}

private:
	int value;
};

int main() {
	Equals eq(123);
	cout << eq(12, 111) << endl;	
	cout << eq(123) << endl;	//1 true
}