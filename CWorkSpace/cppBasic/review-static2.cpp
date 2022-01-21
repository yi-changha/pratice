//Á¤Àû ¸â¹ö

#include <iostream>

using namespace std;


class Color {
public:
	Color() : r(0), g(0), b(0), id(idCounter++) {}
	Color(float r, float g, float b) : r(r), g(g), b(b) , id(idCounter++) {}

	float GetR() { return r; }
	float GetG() { return g; }
	float GetB() { return b; }

	int GetId() { return id; }

	static Color MixColors(Color a, Color b) {
		return Color((a.r + b.r) / 2, (a.g + b.g) / 2, (a.b + b.b) / 2);
	}

	static int idCounter;

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

	cout << "r = " << purple.GetR() << ", g = " << purple.GetG() << ", b = " << purple.GetB() << endl;

	cout << "blue.GetId() = " << blue.GetId() << endl;
	cout << "red.GetId() = " << red.GetId() << endl;
	cout << "purple.GetId() = " << purple.GetId() << endl;
}