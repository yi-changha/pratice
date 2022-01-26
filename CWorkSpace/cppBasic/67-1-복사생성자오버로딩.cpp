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
		// char포인터는 문자열로 취급할 수 있어서 컴파일러가 구분하지 못함.
		//(void*) 주소값만 저장하는 포인터. 자료형 정보 없음
		// -> 가리키는 값을 바꿀 수 없음.

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
		// 해제된 메모리에 대한 접근을 막기 위해 NULL로 초기화
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

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
}