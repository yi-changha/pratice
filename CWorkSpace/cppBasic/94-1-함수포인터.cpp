// �Լ� ������

#include <iostream>
using namespace std;

bool compare(int a, int b) {
	return a == b;
}

int main() {
	bool(*fp)(int, int) = compare;		// ������, int �� ���� �޾� bool�� return
	//fp = compare;				// �Լ� ������, &compare == compare
	bool res = fp(2, 2);		// �Լ� ������, *fp() == fp()
	
	cout << res << endl;
}