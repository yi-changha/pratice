//Å¬·¡½º
// Ä¸½¶È­

#include <iostream>

using namespace std;

struct TV {
private:
	bool powerOn;
	int channel;
	int volume;

public:
	void on() {
		powerOn = true;
		cout << "TV¸¦ Ä×½À´Ï´Ù." << endl;
	}

	void off() {
		powerOn = false;
		cout << "TV¸¦ ²°½À´Ï´Ù." << endl;
	}

	void setChannel(int cnl) {
		if (cnl >= 1 && cnl <= 999) {
			channel = cnl;
			cout << "Ã¤³ÎÀ» " << cnl << "(À¸)·Î ¹Ù²å½À´Ï´Ù." << endl;
		}
	}
	void setVolume(int vol) {
		if (vol >= 0 && vol <= 100) {
			volume = vol;
			cout << "º¼·ýÀ» " << vol << "(À¸)·Î ¹Ù²å½À´Ï´Ù." << endl;
		}
	}
};

int main() {
	TV lg;
	lg.on();
	lg.setChannel(10);
	lg.setVolume(50);
}