// 함수 템플릿

#include <iostream>
#include <string>
using namespace std;

class Vector2 {
public:
	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}
	float GetX() const { return x; }
	float GetY() const { return y; }

	Vector2 &operator+=(const Vector2 &rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

private:
	float x, y;
};

template<typename T>
T getArraySum(const T arr[], int n) {
	T sum = T();		// 초기화
	//Vector2 sum = 0 이면, int 내보내야되는데 변환 출력자 없음.
	//T의 기본 생성자를 넣고 호출

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int		iarr[5] = { 3, 1, 4, 1, 5 };
	float	farr[5] = { 3.5, 4.6, 7.4, 2.5, 7.1 };
	Vector2 varr[3] = { Vector2(1,2), Vector2(3,4), Vector2(5,6) };
	string	sarr[3] = { "hello", "world", "lee" };

	int		isum = getArraySum<int>(iarr, 5);
	float	fsum = getArraySum<float>(farr, 5);
	Vector2 vsum = getArraySum<Vector2>(varr, 3);
	string	ssum = getArraySum<string>(sarr, 3);

	cout << isum << endl;
	cout << fsum << endl;
	cout << vsum.GetX() << "," << vsum.GetY() << endl;
	cout << ssum << endl;
}