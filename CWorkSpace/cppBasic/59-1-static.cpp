#include <iostream>

using namespace std;

class Color {
public:
	Color() : r(0), g(0), b(0), id(idCounter++) {}
	Color(float r, float g, float b) : r(r), g(g), b(b), id(idCounter++) {}

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }

	int GetId() { return id; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}

	static int idCounter;
	//static int idCounter = 1; 
	// 정적으로 선언된 것은 class안에서 초기값을 줄 수 없음.

	// idCounter를 전역변수가 아닌 class안에 넣었을 때 장점
	// 1. private에 접근할 수 있다.
	// 2. 전역변수에 있으면 클래스에 따라 다른 전역변수를 선언하게 됨
	//   -> 그 결과 전역변수가 늘어나고, 프로그램이 난잡해짐!
	// => 전역 변수나 전역 함수는 최대한 줄이는 게 좋음

private:
	float r;
	float g;
	float b;

	int id;
};

int Color::idCounter = 1;

int main() {
	Color blue(0, 0, 1);
	Color red(1, 0, 0);

	Color purple = Color::MixColors(blue, red);

	cout << "r = " << purple.GetR() << ",g = " << purple.GetG() << ",b = " << purple.GetB() << endl;


	cout << "blue.GetId() = " << blue.GetId() << endl;
	cout << "red.GetId() = " << red.GetId() << endl;
	cout << "purple.GetId() = " << purple.GetId() << endl;
}