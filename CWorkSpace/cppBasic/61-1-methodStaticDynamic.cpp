// 멤버 메서드의 선언, 정의 분리하기
// 분리하는 이유 : 함수의 순서에 따라 관계를 끼워맞추기가 어려워짐.
// 분리하면 관계를 끼워맞추는 것이 쉬워짐.

#include <iostream>

using namespace std;

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);

	float GetX() const;
	float GetY() const;

	// 정적 메써드, 어떤 것에 어떤 것을 더해야할 지 알려줘야함
	static Vector2 Sum(Vector2 a, Vector2 b) {
		return Vector2(a.x + b.x, a.y + b.y);
		//return Vector2(a.GetX() + b.GetX(), a.GetY() + b.GetY());
	}

	// 동적 메써드, 이미 포함된 개체와 rhs와의 연산
	Vector2 Add(Vector2 rhs) {	//rhs(right hand side): 우변, 연산자 우측
		return Vector2(x + rhs.x, y + rhs.y);
	}

private:
	float x;
	float y;
};


int main() {
	Vector2 a(2, 3);
	Vector2 b(-1, 4);
	Vector2 c1 = Vector2::Sum(a, b);
	Vector2 c2 = a.Add(b);

	//Vector2 c = a + b; 
	//class와 class를 더해야함. 컴퓨터는 객체와 객체를 더하는 법을 몰라서 오류가 남.
	// => 연산자 오버로딩을 통해 해결. 이번 예제는 다른 방법 이용

	cout << a.GetX() << ", " << a.GetY() << endl;
	cout << b.GetX() << ", " << b.GetY() << endl;
	cout << c1.GetX() << ", " << c1.GetY() << endl;
	cout << c2.GetX() << ", " << c2.GetY() << endl;

}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::GetX() const { return x; }
float Vector2::GetY() const { return y; }