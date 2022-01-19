//연산자 오버로딩

#include <iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const;
	float GetY() const;

	//멤버 연산자 : 자기자신 + 매개 변수
	Vector2 operator+(const Vector2 rhs) const;
	Vector2 operator-(const Vector2 rhs) const;
	Vector2 operator*(const float rhs) const;
	Vector2 operator/(const float rhs) const;
	float operator*(const Vector2 rhs) const;

private:
	float x;
	float y;
};

//비멤버 연산자 : 전역; 좌변 매개변수 + 우변 매개변수
//매개변수 2개 (좌변 매개변수, 우변 매개변수)
Vector2 operator*(const float a, const Vector2 b) {
	return Vector2(a * b.GetX(), a * b.GetY());
}

int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = a + b;
	Vector2 c2 = a - b;
	Vector2 c3 = a * 1.6;
	Vector2 c4 = a / 2;
	float c5 = a * b;
	Vector2 c6 = 1.6 * a;
	// operator+ 를 쓰면  a + b 연산자 계산이 가능해짐, 연산자 오버로딩
	//Vector2 c3 = (1.6).operator*(a); 
	// C언어 기본 자료형은 객체가 아니기 때문에 operator를 통한 연산 불가.

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c1.GetX() << ", " << c1.GetY() << endl;
	cout << c2.GetX() << ", " << c2.GetY() << endl;
	cout << c3.GetX() << ", " << c3.GetY() << endl;
	cout << c4.GetX() << ", " << c4.GetY() << endl;
	cout << c5 << endl;
	cout << c6.GetX() << ", " << c6.GetY() << endl;

}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }

Vector2 Vector2::operator+(const Vector2 rhs) const {
	return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2 rhs) const {
	return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(const float rhs) const {
	return Vector2(x*rhs, y*rhs);
}
Vector2 Vector2::operator/(const float rhs) const {
	return Vector2(x / rhs, y / rhs);
}
float Vector2::operator*(const Vector2 rhs) const {
	return x * rhs.x + y * rhs.y;
}