// const의 쓰임새
// 1. 매개변수의 상수화 (모든 함수)
// 2. 메서드의 상수화 (멤버 메서드)

// 메서드의 상수화
// : 한 메서드 안에서 자기가 속한 다른 클래스의 멤버 변수를 건드릴 수 없게 막음.


#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}

	void Deposit(const int d) {	// 입력된 d를 수정할수 없게 함.
		//d = money;			//오류, d값을 수정해서 값 오류를 만듬.
		money += d;
		cout << d << "원을 예금했습니다." << endl;
	}
	void Draw(int d) {
		if (money >= d) {
			money -= d;
			cout << d << "원을 인출했습니다." << endl;
		}
	}

	int ViewMoney() const {
		//money++;				// 오류, 잔고 확인 시마다 1원씩 증가하게 됨.
		return money;
	}

	//const int ViewMoney() {} 
	// 함수의 앞에 const를 붙일 수 있으나, 상수형 메서드는 아님.
	// 대부분의 경우 의미가 없으나, 간혹 쓰임.

private:
	int money;
};

int main() {
	Account lee(200);
	
	lee.Deposit(100);
	lee.Draw(20);

	cout << "현재 잔고 : " <<lee.ViewMoney() << "원" << endl;
}