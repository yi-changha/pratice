// ��������, ��������

#include <iostream>
using namespace std;

class String {
public:
	String() {		//�Ű����� ���� ��
	// ���� �ʱ�ȭ
		strData = NULL;		//NULL, strData��� �����Ͱ� ����Ű�� �� ����.
		len = 0;
	}
	String(const char *str) { //�Ű����� ���� ��
		len = strlen(str);
		strData = new char[len + 1];
		strcpy(strData, str);	//���� ���縦 ���� strcpy �̿�
	}

	~String() {
		delete[] strData;
	}

	char *GetStrData() const {	// ��ȯ ������ char ������
		return strData;
	}

	int GetLen() const {
		return len;
	}

private:
	char *strData;		
	// ���ڿ� �����Ҵ� �� �����Ҵ��� �ּҸ� ������ ������

	int len;	// ���ڿ��� ����
};

int main() {
	String s;
}