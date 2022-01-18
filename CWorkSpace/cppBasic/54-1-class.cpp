// Ŭ���� = �ڷ� ���� + �ڷ� ó�� = ���� + �Լ�
// Ŭ����(Ÿ��) : Ư���� �뵵�� �����ϱ� ���� ������ �Լ��� ��� �� ��(�ڷ���)
// ��ü(������Ʈ) : Ŭ������ �̿��Ͽ� �� ��ü(����, �޸� ���� ����)

#include <iostream>

using namespace std;

// �������������� : private, protected, public
// struct - �⺻ public
// class - �⺻ private

struct TV {
private:
	bool powerOn;
	int channel;
	int volume;

public:
	void on() {
		powerOn = true;
		cout << "TV�� �׽��ϴ�." << endl;
	}

	void of() {
		powerOn = false;
		cout << "TV�� �����ϴ�." << endl;
	}

	void setChannel(int cnl) {
		if (cnl >= 1 && cnl <= 999) {
			channel = cnl;
			cout << "ä���� " << cnl << "(��)�� �ٲ���ϴ�." << endl;
		}
	}

	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "������" << vol << "(��)�� �ٲ���ϴ�." << endl;
		}
	}
};

int main() {
	TV lg;
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);
}