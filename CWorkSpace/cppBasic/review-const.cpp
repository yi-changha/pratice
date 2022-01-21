//상수형 매개변수와 상수형 메서드

#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}


	void Deposit(const int d) {
		money += d;
		cout << d << "원 예금" << endl;
	}
	void Draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << "원 인출" << endl;
		}
	}
	int ViewMoney() const {
		return money;
	}

private:
	int money;
};

int main() {
	Account lee(100);

	lee.Deposit(100);
	lee.Draw(20);

	cout << "현재 잔고 : " << lee.ViewMoney() << endl;
}