//����� �Ű������� ����� �޼���

#include <iostream>

using namespace std;

class Account {
public:
	Account() : money(0) {}
	Account(int money) : money(money) {}


	void Deposit(const int d) {
		money += d;
		cout << d << "�� ����" << endl;
	}
	void Draw(const int d) {
		if (money >= d) {
			money -= d;
			cout << d << "�� ����" << endl;
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

	cout << "���� �ܰ� : " << lee.ViewMoney() << endl;
}