// 깊은복사, 얕은복사
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
	String() {
		cout << "Sting() 생성자 호출" << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "Sting(const char*) 생성자 호출" << endl;
		len = strlen(str);
		strData = new char[len + 1]; // null 문자를 고려해 len+1만큼 할당
		cout << "strData 할당 : " << (void*)strData << endl;
		strcpy(strData, str);	//깊은 복사 strcpy
	}

	String(const String &rhs) {
		cout << "Sting(String &rhs) 생성자 호출" << endl;
		strData = new char[rhs.len + 1];
		cout << "strData 할당 : " << (void*)strData << endl;
		strcpy(strData, rhs.strData);
		len = rhs.len; // 깊은 복사
	}

	~String() {
		cout << "~String() 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		strData = NULL;
	}

	String &operator=(const String &rhs) {	//개체복사를 하지 않기 위해 레퍼렌스 변수 이용
		if (this != &rhs) {
			delete[] strData;
			strData = new char[rhs.len + 1];
			cout << "strData 할당 : " << (void*)strData << endl;
			strcpy(strData, rhs.strData);
			len = rhs.len; // 깊은 복사
		}
		return *this;
	}

	char *GetStrData() const {
		return strData;
	}

	int GetLen() const {
		return len;
	}

private:
	char *strData;
	int len;
};

int main() {
	String s1("안녕");
	String s2(s1);		// 복사 생성자
	String s3;
	s3.operator=(s1);		// 연산자 오버로딩 이용

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
}