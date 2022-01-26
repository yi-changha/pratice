// 비타입 파라미터
// 제한적으로 정수 자료형, 포인터에 대해 비타입 파라미터 사용가능

#include <iostream>
using namespace std;

template<typename T, int n>		//int n 벡터의 차원
class Vector {
public:
	T GetComp(int i) const {	// i번째 성분을 리턴
		return comp[i];
	}
	void SetComp(int i, T val) {
		comp[i] = val;
	}
	Vector operator+(const Vector &rhs) const {
		Vector res;
		for (int i = 0; i < n; i++) {
			res.comp[i] = this->comp[i] + rhs.comp[i];
			//res.SetComp(i, this->GetComp(i) + rhs.GetComp(i));
		}
		return res;
	}

private:
	T comp[n]; // 벡터의 성분
};

int main() {
	Vector<float, 3> v1, v2;
	Vector<float, 2> v4;
	v1.SetComp(0, 2);
	v1.SetComp(1, 3);
	v1.SetComp(2, 4);

	v2.SetComp(0, 5);
	v2.SetComp(1, 6);
	v2.SetComp(2, 7);

	//Vector<float, 3> v3 = v1 + v4; //타입 인수가 달라 에러!

	Vector<float, 3> v3 = v1 + v2;

	cout << v3.GetComp(0) << ", " << v3.GetComp(1) << ", " << v3.GetComp(2) << endl;
}