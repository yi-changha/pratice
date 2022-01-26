// ��������, ��������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
	String() {
		cout << "Sting() ������ ȣ��" << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "Sting(const char*) ������ ȣ��" << endl;
		len = strlen(str);
		strData = new char[len + 1]; // null ���ڸ� ����� len+1��ŭ �Ҵ�
		cout << "strData �Ҵ� : " << (void*)strData << endl;
		strcpy(strData, str);	//���� ���� strcpy
	}

	String(const String &rhs) {
		cout << "Sting(String &rhs) ������ ȣ��" << endl;
		strData = new char[rhs.len + 1];
		cout << "strData �Ҵ� : " << (void*)strData << endl;
		strcpy(strData, rhs.strData);
		len = rhs.len; // ���� ����
	}

	~String() {
		cout << "~String() �Ҹ��� ȣ��" << endl;
		delete[] strData;
		cout << "strData ������ : " << (void*)strData << endl;
		strData = NULL;
	}

	String &operator=(const String &rhs) {	//��ü���縦 ���� �ʱ� ���� ���۷��� ���� �̿�
		if (this != &rhs) {
			delete[] strData;
			strData = new char[rhs.len + 1];
			cout << "strData �Ҵ� : " << (void*)strData << endl;
			strcpy(strData, rhs.strData);
			len = rhs.len; // ���� ����
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
	String s1("�ȳ�");
	String s2(s1);		// ���� ������
	String s3;
	s3.operator=(s1);		// ������ �����ε� �̿�

	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
}