// 깊은복사, 얕은복사

#include <iostream>
using namespace std;

class String {
public:
	String() {		//매개변수 없을 때
	// 변수 초기화
		strData = NULL;		//NULL, strData라는 포인터가 가리키는 값 없다.
		len = 0;
	}
	String(const char *str) { //매개변수 있을 때
		len = strlen(str);
		strData = new char[len + 1];
		strcpy(strData, str);	//깊은 복사를 위해 strcpy 이용
	}

	~String() {
		delete[] strData;
	}

	char *GetStrData() const {	// 반환 형식이 char 포인터
		return strData;
	}

	int GetLen() const {
		return len;
	}

private:
	char *strData;		
	// 문자열 동적할당 후 동적할당한 주소를 저장할 포인터

	int len;	// 문자열의 길이
};

int main() {
	String s;
}