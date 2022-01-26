// 클래스 템플릿

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Vector2 {
public:
	Vector2() : x(0), y(0) {}
	Vector2(T x, T y) : x(x), y(y) {}
	T GetX() const { return x; }
	T GetY() const { return y; }
	Vector2 operator+(const Vector2 &rhs) const {
		return Vector2(x + rhs.x, y + rhs.y);
	}
	Vector2 operator-(const Vector2 &rhs) const {
		return Vector2(x - rhs.x, y - rhs.y);
	}
	Vector2 &operator+=(const Vector2 &rhs) const {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vector2 &operator-=(const Vector2 &rhs) const {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

private:
	T x, y;
};

template<typename T>
T getArraySum(const T arr[], int n) {
	T sum = T();
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	Vector2<float> v1(2, 3);
	Vector2<float> v2(2, 3);
	Vector2<float> v3 = v1 + v2;
}